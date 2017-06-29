#include "stdafx.h"
#include "HelpTools.h"
#include <windows.h>
#include <tlhelp32.h>
#include <boost/foreach.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


HelpTools::HelpTools()
{
}


HelpTools::~HelpTools()
{
}

BOOL HelpTools::isStringNullOrWhitespace(std::string str)
{
	BOOST_FOREACH(char ch,str)
	{
		if (!isspace(ch))
			return FALSE;
	}
	return TRUE;
}

BOOL HelpTools::isStringNullOrWhitespace(LPSTR str)
{
	BOOST_FOREACH(char ch, str)
	{
		if (!isspace(ch))
			return FALSE;
	}
	return TRUE;
}

BOOL HelpTools::isStringNullOrWhitespace(std::wstring str)
{
	BOOST_FOREACH(wchar_t ch, str)
	{
		if (!iswspace(ch))
			return FALSE;
	}
	return TRUE;
}

BOOL HelpTools::isStringNullOrWhitespace(LPWSTR str)
{
	BOOST_FOREACH(wchar_t ch, str)
	{
		if (!iswspace(ch))
			return FALSE;
	}
	return TRUE;
}

BOOL HelpTools::isStringNullOrWhitespace(LPCSTR str)
{
	BOOST_FOREACH(wchar_t ch, str)
	{
		if (!isspace(ch))
			return FALSE;
	}
	return TRUE;
}

BOOL HelpTools::isStringNullOrWhitespace(LPCWSTR str)
{
	BOOST_FOREACH(wchar_t ch, str)
	{
		if (!iswspace(ch))
			return FALSE;
	}
	return TRUE;
}

std::string HelpTools::serialize(MyMap map)
{
	std::string str;
	std::ostringstream ss();
	//boost::archive::text_oarchive oar(ss);

	return std::string();
}

HANDLE HelpTools::GetProcessHandleByName(LPWSTR name)
{
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);
	HANDLE proc = NULL;
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	
	if (Process32First(snapshot, &entry))
	{
		while (Process32Next(snapshot,&entry))
		{
			if (wcscmp(entry.szExeFile, name)==0)
			{
				proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
			}
		}
	}

	return proc;
}



