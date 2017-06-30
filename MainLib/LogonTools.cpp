#include "stdafx.h"
#include "LogonTools.h"
#include "MacroHelp.h"
#include <VersionHelpers.h>
#include <UserEnv.h>
#include <algorithm>
#include "HelpTools.h"

namespace Logon
{

	LogonTools::LogonTools()
	{
		this->si.cb = sizeof(STARTUPINFO);
	}


	LogonTools::~LogonTools()
	{
	}

	BOOL LogonTools::LogIn(LPCWSTR username, LPCWSTR password, LPCWSTR domain = L".")
	{
		try
		{
			return LogonUser(username, domain, password, LOGON32_LOGON_INTERACTIVE,
				LOGON32_PROVIDER_DEFAULT, &this->hToken);
		}
		catch (...)
		{
			return FALSE;
		}
	}

	BOOL LogonTools::isUserInAdminGroup()
		/*
		 *
		 */
	{
		BOOL fInAdminGroup = FALSE;
		DWORD dwError = ERROR_SUCCESS;
		HANDLE hToken = NULL;
		HANDLE hTokenToCheck = NULL;
		DWORD cbSize = 0;
		OSVERSIONINFO osver = { sizeof(osver) };
		auto Cleanup = [&]() mutable -> BOOL {
			// Centralized cleanup for all allocated resources.
			if (hToken)
			{
				CloseHandle(hToken);
				hToken = NULL;
			}
			if (hTokenToCheck)
			{
				CloseHandle(hTokenToCheck);
				hTokenToCheck = NULL;
			}

			// Throw the error if something failed in the function.
			if (ERROR_SUCCESS != dwError)
			{
				throw dwError;
			}

			return FALSE;
		};
		// Open the primary access token of the process for query and duplicate.
		if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY | TOKEN_DUPLICATE,
			&hToken))
		{
			dwError = GetLastError();
			return Cleanup();
		}

		// Determine whether system is running Windows Vista or later operating 
		// systems (major version >= 6) because they support linked tokens, but 
		// previous versions (major version < 6) do not.
		/*if (!GetVersionEx(&osver))
		{
			dwError = GetLastError();
			goto Cleanup;
		}
		*/
		if (IsWindowsVistaOrGreater())
		{
			// Running Windows Vista or later (major version >= 6). 
			// Determine token type: limited, elevated, or default. 
			TOKEN_ELEVATION_TYPE elevType;
			if (!GetTokenInformation(hToken, TokenElevationType, &elevType,
				sizeof(elevType), &cbSize))
			{
				dwError = GetLastError();
				return Cleanup();
			}

			// If limited, get the linked elevated token for further check.
			if (TokenElevationTypeLimited == elevType)
			{
				if (!GetTokenInformation(hToken, TokenLinkedToken, &hTokenToCheck,
					sizeof(hTokenToCheck), &cbSize))
				{
					dwError = GetLastError();
					return Cleanup();
				}
			}
		}

		// CheckTokenMembership requires an impersonation token. If we just got a 
		// linked token, it already is an impersonation token.  If we did not get 
		// a linked token, duplicate the original into an impersonation token for 
		// CheckTokenMembership.
		if (!hTokenToCheck)
		{
			if (!DuplicateToken(hToken, SecurityIdentification, &hTokenToCheck))
			{
				dwError = GetLastError();
				return Cleanup();
			}
		}

		// Create the SID corresponding to the Administrators group.
		BYTE adminSID[SECURITY_MAX_SID_SIZE];
		cbSize = sizeof(adminSID);
		if (!CreateWellKnownSid(WinBuiltinAdministratorsSid, NULL, &adminSID,
			&cbSize))
		{
			dwError = GetLastError();
			return Cleanup();
		}

		// Check if the token to be checked contains admin SID.
		// http://msdn.microsoft.com/en-us/library/aa379596(VS.85).aspx:
		// To determine whether a SID is enabled in a token, that is, whether it 
		// has the SE_GROUP_ENABLED attribute, call CheckTokenMembership.
		if (!CheckTokenMembership(hTokenToCheck, &adminSID, &fInAdminGroup))
		{
			dwError = GetLastError();
			return Cleanup();
		}

		//Cleanup:
			// Centralized cleanup for all allocated resources.
		if (hToken)
		{
			CloseHandle(hToken);
			hToken = NULL;
		}
		if (hTokenToCheck)
		{
			CloseHandle(hTokenToCheck);
			hTokenToCheck = NULL;
		}

		// Throw the error if something failed in the function.
		if (ERROR_SUCCESS != dwError)
		{
			throw dwError;
		}

		return fInAdminGroup;

	}

	BOOL LogonTools::IsRunAsAdmin()
	{
		BOOL fIsRunAsAdmin = FALSE;
		DWORD dwError = ERROR_SUCCESS;
		PSID pAdministratorsGroup = NULL;
		auto Cleanup = [&]() mutable->BOOL
		{
			if (pAdministratorsGroup)
			{
				FreeSid(pAdministratorsGroup);
				pAdministratorsGroup = NULL;
			}

			// Throw the error if something failed in the function.
			if (ERROR_SUCCESS != dwError)
			{
				throw dwError;
			}

			return fIsRunAsAdmin;
		};
		// Allocate and initialize a SID of the administrators group.
		SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
		if (!AllocateAndInitializeSid(
			&NtAuthority,
			2,
			SECURITY_BUILTIN_DOMAIN_RID,
			DOMAIN_ALIAS_RID_ADMINS,
			0, 0, 0, 0, 0, 0,
			&pAdministratorsGroup))
		{
			dwError = GetLastError();
			return  Cleanup();
		}

		// Determine whether the SID of administrators group is enabled in 
		// the primary access token of the process.
		if (!CheckTokenMembership(NULL, pAdministratorsGroup, &fIsRunAsAdmin))
		{
			dwError = GetLastError();
			return Cleanup();
		}

		//Cleanup:
			// Centralized cleanup for all allocated resources.
		if (pAdministratorsGroup)
		{
			FreeSid(pAdministratorsGroup);
			pAdministratorsGroup = NULL;
		}

		// Throw the error if something failed in the function.
		if (ERROR_SUCCESS != dwError)
		{
			throw dwError;
		}

		return fIsRunAsAdmin;
	}

	BOOL LogonTools::IsProcessElevated()
	{
		BOOL fIsElevated = FALSE;
		DWORD dwError = ERROR_SUCCESS;
		HANDLE hToken = NULL;
		auto Cleanup = [&]() mutable->BOOL
		{
			// Centralized cleanup for all allocated resources.
			if (hToken)
			{
				CloseHandle(hToken);
				hToken = NULL;
			}

			// Throw the error if something failed in the function.
			if (ERROR_SUCCESS != dwError)
			{
				throw dwError;
			}

			return fIsElevated;

		};
		// Open the primary access token of the process with TOKEN_QUERY.
		if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
		{
			dwError = GetLastError();
			return Cleanup();
		}

		// Retrieve token elevation information.
		TOKEN_ELEVATION elevation;
		DWORD dwSize;
		if (!GetTokenInformation(hToken, TokenElevation, &elevation,
			sizeof(elevation), &dwSize))
		{
			// When the process is run on operating systems prior to Windows 
			// Vista, GetTokenInformation returns FALSE with the 
			// ERROR_INVALID_PARAMETER error code because TokenElevation is 
			// not supported on those operating systems.
			dwError = GetLastError();
			return Cleanup();
		}

		fIsElevated = elevation.TokenIsElevated;

		//Cleanup:
			// Centralized cleanup for all allocated resources.
		if (hToken)
		{
			CloseHandle(hToken);
			hToken = NULL;
		}

		// Throw the error if something failed in the function.
		if (ERROR_SUCCESS != dwError)
		{
			throw dwError;
		}

		return fIsElevated;

	}

	DWORD LogonTools::GetProcessIntegrityLevel()
	{
		DWORD dwIntegrityLevel = 0;
		DWORD dwError = ERROR_SUCCESS;
		HANDLE hToken = NULL;
		DWORD cbTokenIL = 0;
		PTOKEN_MANDATORY_LABEL pTokenIL = NULL;
		auto Cleanup = [&]() mutable->BOOL
		{
			// Centralized cleanup for all allocated resources.
			if (hToken)
			{
				CloseHandle(hToken);
				hToken = NULL;
			}
			if (pTokenIL)
			{
				LocalFree(pTokenIL);
				pTokenIL = NULL;
				cbTokenIL = 0;
			}

			// Throw the error if something failed in the function.
			if (ERROR_SUCCESS != dwError)
			{
				throw dwError;
			}

			return dwIntegrityLevel;
		};
		// Open the primary access token of the process with TOKEN_QUERY.
		if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
		{
			dwError = GetLastError();
			return  Cleanup();
		}

		// Query the size of the token integrity level information. Note that 
		// we expect a FALSE result and the last error ERROR_INSUFFICIENT_BUFFER
		// from GetTokenInformation because we have given it a NULL buffer. On 
		// exit cbTokenIL will tell the size of the integrity level information.
		if (!GetTokenInformation(hToken, TokenIntegrityLevel, NULL, 0, &cbTokenIL))
		{
			if (ERROR_INSUFFICIENT_BUFFER != GetLastError())
			{
				// When the process is run on operating systems prior to Windows 
				// Vista, GetTokenInformation returns FALSE with the 
				// ERROR_INVALID_PARAMETER error code because TokenElevation 
				// is not supported on those operating systems.
				dwError = GetLastError();
				return Cleanup();
			}
		}

		// Now we allocate a buffer for the integrity level information.
		pTokenIL = (TOKEN_MANDATORY_LABEL *)LocalAlloc(LPTR, cbTokenIL);
		if (pTokenIL == NULL)
		{
			dwError = GetLastError();
			return Cleanup();
		}

		// Retrieve token integrity level information.
		if (!GetTokenInformation(hToken, TokenIntegrityLevel, pTokenIL,
			cbTokenIL, &cbTokenIL))
		{
			dwError = GetLastError();
			return Cleanup();
		}

		// Integrity Level SIDs are in the form of S-1-16-0xXXXX. (e.g. 
		// S-1-16-0x1000 stands for low integrity level SID). There is one and 
		// only one subauthority.
		dwIntegrityLevel = *GetSidSubAuthority(pTokenIL->Label.Sid, 0);

		//Cleanup:
			// Centralized cleanup for all allocated resources.
		if (hToken)
		{
			CloseHandle(hToken);
			hToken = NULL;
		}
		if (pTokenIL)
		{
			LocalFree(pTokenIL);
			pTokenIL = NULL;
			cbTokenIL = 0;
		}

		// Throw the error if something failed in the function.
		if (ERROR_SUCCESS != dwError)
		{
			throw dwError;
		}

		return dwIntegrityLevel;

	}

	void LogonTools::ReportError(LPCWSTR pszFunction, DWORD dwError)
	{
		wchar_t szMessage[200];
		/*if (SUCCEEDED(StringCchPrintf(szMessage, ARRAYSIZE(szMessage),
			L"%s failed w/err 0x%08lx", pszFunction, dwError)))
		{
			MessageBox(NULL, szMessage, L"Error", MB_ICONERROR);
		}*/
	}

	BOOL LogonTools::CreateEnviroment()
	{
		//	LPVOID lpEnv;
			//HANDLE hToken = this->hToken;
		msgbx("Create env");
		return CreateEnvironmentBlock(&lpEnv, hToken, TRUE);
		//return FALSE;
	}

	BOOL LogonTools::GetUserProfileDir()
	{
		WCHAR szUserProfiletmp[256] = L"";
		HANDLE hTokentmp = this->hToken;
		DWORD dwSize2;
		return GetUserProfileDirectory(hTokentmp, szUserProfile, &dwSize2);
		///		int i = 0;
		BOOL result = HelpTools::isStringNullOrWhitespace(szUserProfiletmp);
		//this->szUserProfile = szUserProfiletmp;

		return result;
	}



	BOOL LogonTools::CreateProcessWithUser(ProcessRunDataW *data)
	{
		PROCESS_INFORMATION pi1 = { 0 };
		STARTUPINFO         si1 = { 0 };
		si1.cb = sizeof(STARTUPINFO);
		(!CreateProcessWithLogonW(data->getUser(), data->getDomain(), data->getPassword(),
			LOGON_WITH_PROFILE, data->getProcessName(), data->getCommandLineArgs(),
			CREATE_UNICODE_ENVIRONMENT, lpEnv, szUserProfile,
			&si1, &pi1));
		int iii = 0;
		/*if (!result)
			msgbxw(L"CreateProcessWithLogonW");*/
		return FALSE;
	}

	BOOL LogonTools::RunProcessAsUser(ProcessRunDataW* data)
	{
		if (data->getRunType() != RunType::User)
			return FALSE;
		msgbxw(data->getUser());
		if (!LogIn(data->getUser(), data->getPassword(), data->getDomain()))
			return FALSE;

		if (!CreateEnviroment())
			return FALSE;

		if (!GetUserProfileDir())
			return FALSE;

		if (!CreateProcessWithUser(data))
			return FALSE;

		if (!DestroyEnviroment())
			return FALSE;
		delete data;
		return TRUE;
	}

	BOOL LogonTools::RunProcessAsToken(ProcessRunData * data)
	{
		return 0;
	}

	VOID LogonTools::MsgBx(LPCWSTR str)
	{
		MessageBox(NULL, str, str, 0);
	}


	BOOL LogonTools::DestroyEnviroment()
	{
		return DestroyEnvironmentBlock(this->lpEnv);
	}




}
