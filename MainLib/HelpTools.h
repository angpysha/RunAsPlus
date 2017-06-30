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
	static std::string compress(std::string str);
	static std::string compressEx(std::string str);
	static std::string decompressEx(std::string &str);
};

