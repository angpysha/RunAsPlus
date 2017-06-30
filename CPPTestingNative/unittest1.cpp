#include "stdafx.h"
#include "CppUnitTest.h"
#include "MainLib.h"
//#include <HelpTools.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define DisplayError(a) MessageBox(NULL,a,a,NULL);
namespace CPPTestingNative
{		
	TEST_CLASS(NativeTesting)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
		}

		TEST_METHOD(TestMap)
		{
			MsgBx(L"rterfa");
		}

		/*TEST_METHOD(TestRuning)
		{
			MyMap map;
			map.insert(MyMap::value_type(PData::user, L"aaa"));
			map.insert(MyMap::value_type(PData::domain, L""));
			map.insert(MyMap::value_type(PData::password, L"111"));
			map.insert(MyMap::value_type(PData::processName, L"cmd.exe"));
			map.insert(MyMap::value_type(PData::commandLineArgs, L""));
			map.insert(MyMap::value_type(PData::type, L"0"));

			LogInAsUser(map);
		}*/

		TEST_METHOD(TstRun)
		{
			Logon::ProcessRunDataW* data = new Logon::ProcessRunDataW();
			data->setUser(L"user2");
			data->setPassword(L"1111");
			data->setDomain(L".");
			data->setProcessName(L"cmd.exe");
			//data->setCommandLineArgs(L"");
			data->setRunType(RunType::User);
			RunAsUser(data);
		}

		TEST_METHOD(TstMthdd)
		{
			DWORD     dwSize;
			HANDLE    hToken;
			LPVOID    lpvEnv;
			PROCESS_INFORMATION pi = { 0 };
			STARTUPINFO         si = { 0 };
			WCHAR               szUserProfile[256] = L"";

			si.cb = sizeof(STARTUPINFO);

			/*if (argc != 4)
			{
				wprintf(L"Usage: %s [user@domain] [password] [cmd]", argv[0]);
				wprintf(L"\n\n");
				return;
			}*/

			//
			// TO DO: change NULL to '.' to use local account database
			//
			if (!LogonUser(L"aaa", NULL,L"1111", LOGON32_LOGON_INTERACTIVE,
				LOGON32_PROVIDER_DEFAULT, &hToken))
				DisplayError(L"LogonUser");

			if (!CreateEnvironmentBlock(&lpvEnv, hToken, TRUE))
				DisplayError(L"CreateEnvironmentBlock");

			dwSize = sizeof(szUserProfile) / sizeof(WCHAR);

			if (!GetUserProfileDirectory(hToken, szUserProfile, &dwSize))
				DisplayError(L"GetUserProfileDirectory");

			//
			// TO DO: change NULL to '.' to use local account database
			//
			int iii = 0;
			if (!CreateProcessWithLogonW(L"aaa", L".", L"1111",
				LOGON_WITH_PROFILE, L"cmd.exe", NULL,
				CREATE_UNICODE_ENVIRONMENT, lpvEnv, szUserProfile,
				&si, &pi))
				DisplayError(L"CreateProcessWithLogonW");

			if (!DestroyEnvironmentBlock(lpvEnv))
				DisplayError(L"DestroyEnvironmentBlock");

			CloseHandle(hToken);
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);

		}

		TEST_METHOD(CheckGetProcessHandleByName)
		{
			LPWSTR name = L"notepad.exe";

			HANDLE df = GetProcessHandleByName(name);
			DWORD id = GetProcessId(df);
			CloseHandle(df);
			WCHAR ll[10];
			swprintf_s(ll, 10, L"%d", id);
			msgbxw(ll);
		}

		TEST_METHOD(checkTextCompression)
		{
			std::string str = "fsdaasdreafafeafafsdfads";

			std::string trt = Compress(str);
			msgbx(trt.c_str());
		}

		

	};


}