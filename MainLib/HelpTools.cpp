#include "stdafx.h"
#include "HelpTools.h"
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



