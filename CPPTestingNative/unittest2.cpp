#include "stdafx.h"
#include "CppUnitTest.h"
#include "MainLib.h"
//#include <HelpTools.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define DisplayError(a) MessageBox(NULL,a,a,NULL);
namespace CPPTestingNative
{
	TEST_CLASS(TestingTexts)
	{
	public:
		TEST_METHOD(TestBase64Encode)
		{
			std::string text = "qwedsvggr5&fafsdlol\\fddfellfrtmnbd";
			std::string enctext = ToBase64(reinterpret_cast<unsigned char const*>(text.c_str()), text.length());
			msgbx(enctext.c_str());
		}

		TEST_METHOD(compressTextTest)
		{
			std::string text = "qwedsvggr5&fafsdlol\\fddfellfrtmnbd";
			std::string comptext = CompressBoost(text);
			msgbx(comptext.c_str());
		}
	};
}