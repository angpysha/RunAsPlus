#include "stdafx.h"
#include "HelpTools.h"
#include <windows.h>
#include <tlhelp32.h>
#include <boost/foreach.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#define ZLIB_WINAPI
#include <sstream>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <base64.h>
//#include <boost/iostream/filter/l>

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

std::string HelpTools::compress(std::string str)
{
	//int compressionLevel = Z_BEST_COMPRESSION;
	//z_stream zs;

	//memset(&zs, 0, sizeof(zs));
	//if (deflateInit(&zs, compressionLevel) != Z_OK)
	//	throw(std::runtime_error("deflateInit failed while compressing."));

	//zs.next_in = (Bytef*)str.data();
	//zs.avail_in = str.size();           // set the z_stream's input

	//int ret;
	//char outbuffer[32768];
	//std::string outstring;

	//do {
	//	zs.next_out = reinterpret_cast<Bytef*>(outbuffer);
	//	zs.avail_out = sizeof(outbuffer);

	//	ret = deflate(&zs, Z_FINISH);

	//	if (outstring.size() < zs.total_out) {
	//		// append the block to the output string
	//		outstring.append(outbuffer,
	//			zs.total_out - outstring.size());
	//	}
	//} while (ret == Z_OK);

	//deflateEnd(&zs);

	//if (ret != Z_STREAM_END) {          // an error occurred that was not EOF
	//	std::ostringstream oss;
	//	oss << "Exception during zlib compression: (" << ret << ") " << zs.msg;
	//	throw(std::runtime_error(oss.str()));
	//}

	//return outstring;

	return std::string();
}

std::string HelpTools::compressEx(std::string str)
{
	std::stringstream compress;
	std::stringstream original;
	//msgbx(str.c_str());
	original << str;
	//msgbx(original.str().c_str());
	boost::iostreams::filtering_streambuf<boost::iostreams::input> out;
	out.push(boost::iostreams::zlib_compressor());
	out.push(original);
	boost::iostreams::copy(out, compress);
	//return compress.str();
	std::string compress_enc = base64_encode(reinterpret_cast<unsigned char const*>(compress.str().c_str()), compress.str().length());
	return compress_enc;
	return std::string();
}

std::string HelpTools::decompressEx(std::string &str)
{
	std::string compressed_encoded;
	std::stringstream decompressed;
	std::string compressed = base64_decode(compressed_encoded);
	std::stringstream compressedstream;
	compressedstream << compressed;

	

	boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
	in.push(boost::iostreams::zlib_decompressor());
	in.push(compressedstream);

	boost::iostreams::copy(in, decompressed);
	return decompressed.str();
	return std::string();
}

HANDLE HelpTools::getProcessToken(HANDLE process)
{
	HANDLE hToken;
	if (!OpenProcessToken(process, TOKEN_DUPLICATE, &hToken))
		return NULL;
	return hToken;
}

HANDLE HelpTools::duplicateProcessToken(HANDLE hToken)
{
	HANDLE hDuplicateToken;
	if (!DuplicateTokenEx(hToken, TOKEN_ASSIGN_PRIMARY | TOKEN_DUPLICATE |
		TOKEN_QUERY | TOKEN_ADJUST_DEFAULT | TOKEN_ADJUST_SESSIONID, NULL,
		SecurityImpersonation, TokenPrimary, &hDuplicateToken))
		return NULL;
	return hDuplicateToken;

}







