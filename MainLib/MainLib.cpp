// MainLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MainLib.h"
#include "ProcessRunData.h"
#include "LogonTools.h"
#include "HelpTools.h"
#include <base64.h>

externC NATIVEFUNC bool Cdecl LogInAsUser(MyMap mymap)
{
	try
	{
		std::shared_ptr<Logon::ProcessRunData> data = std::make_shared<Logon::ProcessRunData>();
		data->setUser(const_cast<LPWSTR>(mymap.left.find(PData::user)->second.c_str()));
		//std::wstring ff = 
		data->setDomain(const_cast<LPWSTR>(mymap.left.find(PData::domain)->second.c_str()));
		data->setPassword(const_cast<LPWSTR>(mymap.left.find(PData::password)->second.c_str()));
		data->setProcessName(const_cast<LPWSTR>(mymap.left.find(PData::processName)->second.c_str()));
		data->setCommandLineArgs(const_cast<LPWSTR>(mymap.left.find(PData::commandLineArgs)->second.c_str()));
		//data->setRunType(_cast<LPWSTR>())
		std::wstring::size_type sz;
		int tmp = std::stoi(mymap.left.find(PData::type)->second, &sz);
		RunType type = static_cast<RunType>(tmp);
		data->setRunType(type);
		std::shared_ptr<Logon::LogonTools> logon_tools{};
		logon_tools->RunProcessAsUser(&*data);
		return true;
	} catch (...)
	{
		return false;
	}
}

externC NATIVEFUNC void Cdecl MsgBx(LPCWSTR str)
/*
 *
 */

try
{
	Logon::LogonTools *helper = new Logon::LogonTools();
	helper->MsgBx(str);
} catch(...)
{

} 

#ifdef __cplusplus
NATIVEFUNC void RunAsUser(Logon::ProcessRunDataW *data)
{
	Logon::LogonTools *logon_tools = new Logon::LogonTools();
	//msgbxw(data->getProcessName());
	logon_tools->RunProcessAsUser(std::move(data));
}
NATIVEFUNC std::string Compress(std::string str)
{
	return HelpTools::compress(str);
	return std::string();
}
NATIVEFUNC std::string CompressBoost(std::string & str)
{
	// std::stringstream compressed();
	//std::stringstream original;
	return HelpTools::compressEx(str);
	return std::string();
}
NATIVEFUNC std::string ToBase64(unsigned char const *str, unsigned int len)
{
	return base64_encode(str, len);

}
NATIVEFUNC std::string FromBase64(std::string const & s)
{
	return base64_decode(s);
}
#endif

NATIVEFUNC VOID RunWithToken(std::string & path, std::string & appToken)
{
	std::wstring ss(appToken.begin(),appToken.end());
	HANDLE hProcess = HelpTools::GetProcessHandleByName(const_cast<LPWSTR>(ss.c_str()));
	HANDLE hToken = HelpTools::getProcessToken(hProcess);
	HANDLE hDupToken = HelpTools::duplicateProcessToken(hToken);
	Logon::ProcessRunDataW *data = new Logon::ProcessRunDataW();
	data->setToken(hDupToken);
	//TODO: Do app path and normal cast to unicode
	Logon::LogonTools *tools = new Logon::LogonTools();
	tools->RunProcessAsToken(data);
}

externC NATIVEFUNC HANDLE Cdecl GetProcessHandleByName(LPWSTR name)
{
	return HelpTools::GetProcessHandleByName(name);
}

externC NATIVEFUNC HANDLE Cdecl GetProcessToken(HANDLE process)
{
	return HelpTools::getProcessToken(process);
}

externC NATIVEFUNC HANDLE Cdecl DuplicateProcessToken(HANDLE hToken)
{
	return HelpTools::duplicateProcessToken(hToken);
}
