#pragma once
#include <string>
#include "MainLib.h"

class HelpTools
{
public:
	HelpTools();
	~HelpTools();
	static BOOL isStringNullOrWhitespace(std::string);
	static BOOL isStringNullOrWhitespace(LPSTR);
	static BOOL isStringNullOrWhitespace(std::wstring);
	static BOOL isStringNullOrWhitespace(LPWSTR);
	static BOOL isStringNullOrWhitespace(LPCSTR);
	static BOOL isStringNullOrWhitespace(LPCWSTR);
	static std::string serialize(MyMap map);
	static HANDLE GetProcessHandleByName(LPWSTR);
};

