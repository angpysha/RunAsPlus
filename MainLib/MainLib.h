#pragma once

#include "HelpMacro.h"
#include <Windows.h>
#include <boost/bimap.hpp>
#include "ProcessRunData.h"
#include <stdio.h>
#include <userenv.h>

enum PData
{
	processName = 0,
	commandLineArgs = 1,
	password = 2,
	user = 3,
	domain = 4,
	type =5
};
#if defined(_UNICODE)
using MyMap = boost::bimap<boost::bimaps::set_of<PData>, std::wstring>;
//using Map = std::map<PData, std::wstring>;
#else
using MyMap = boost::bimap<boost::bimaps::set_of<PData>, std::string>;
using Map = std::map<PData, std::string>;
#endif

externC NATIVEFUNC bool Cdecl LogInAsUser(MyMap);

externC NATIVEFUNC void Cdecl MsgBx(LPCWSTR);
#ifdef __cplusplus
NATIVEFUNC void RunAsUser(Logon::ProcessRunDataW *data);
#endif

externC NATIVEFUNC HANDLE Cdecl GetProcessHandleByName(LPWSTR name);

