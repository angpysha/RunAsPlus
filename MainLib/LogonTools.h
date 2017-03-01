#pragma once
#include <windows.h>
namespace Logon
{
	enum class LogonFlags :DWORD 
	{
		withProfile = LOGON_WITH_PROFILE,
		netCredentials = LOGON_NETCREDENTIALS_ONLY
	};
	enum class CreationFlags:DWORD
	{
		createDefaultErrorMode = CREATE_DEFAULT_ERROR_MODE,
		createNewConsole = CREATE_NEW_CONSOLE,
		createNewProcessGroup = CREATE_NEW_PROCESS_GROUP,
		createSeparateWOWVDM = CREATE_SEPARATE_WOW_VDM,
		createSuspended = CREATE_SUSPENDED,
		createUnicodeEnviroment = CREATE_UNICODE_ENVIRONMENT,
		extendedStartupInfoPresent = EXTENDED_STARTUPINFO_PRESENT
	};


	class LogonTools
	{
	public:
		LogonTools();
		~LogonTools();
		BOOL LogIn(LPCWSTR username, LPCWSTR password, LPCWSTR domain);
		BOOL isUserInAdminGroup();
	private:
		LPVOID lpEnv;
		HANDLE hToken;
		DWORD dwSize;
		PROCESS_INFORMATION pi = { 0 };
		STARTUPINFO si = { 0 };
		WCHAR szUserProfile[256] = L"";
	protected:
	};
}

