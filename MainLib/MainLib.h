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
NATIVEFUNC std::string Compress(std::string str);
NATIVEFUNC std::string ToBase64(unsigned char const*, unsigned int len);
NATIVEFUNC std::string FromBase64(std::string const& s);
NATIVEFUNC std::string CompressBoost(std::string &str);
#endif

externC NATIVEFUNC HANDLE Cdecl GetProcessHandleByName(LPWSTR name);
externC NATIVEFUNC HANDLE Cdecl GetProcessToken(HANDLE process);
externC NATIVEFUNC HANDLE Cdecl DuplicateProcessToken(HANDLE process);

