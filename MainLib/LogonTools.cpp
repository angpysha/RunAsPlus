#include "stdafx.h"
#include "LogonTools.h"
namespace Logon
{

	LogonTools::LogonTools()
	{
		this->si.cb = sizeof(STARTUPINFO);
	}


	LogonTools::~LogonTools()
	{
	}

	BOOL LogonTools::LogIn(LPCWSTR username, LPCWSTR password, LPCWSTR domain=NULL)
	{
		try
		{
			return LogonUser(username, domain, password, LOGON32_LOGON_INTERACTIVE,
				LOGON32_PROVIDER_DEFAULT, &this->hToken);
		} catch(...)
		{
			return FALSE;
		}
	}

	BOOL LogonTools::isUserInAdminGroup()
	{
		
	}


}
