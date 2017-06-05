#pragma once
#include "IProcessRunData.h"
#include "HelpMacro.h"
#pragma region UnicodeDefine
#if defined(_UNICODE)
#define ProcessRunData ProcessRunDataW
#else
#define ProcessRunData ProcessRunDataA
#endif
#pragma endregion
namespace Logon
{
#pragma region UNICODE
	class 	NATIVEFUNC  ProcessRunDataW :
		public IProcessRunData<LPWSTR>
	{
	public:
		ProcessRunDataW();
		/**
		 * \brief
		 */
		~ProcessRunDataW();
		void setProcessName(LPWSTR) override;
		void setCommandLineArgs(LPWSTR) override;
		void setPassword(LPWSTR) override;
		void setUser(LPWSTR) override;
		void setDomain(LPWSTR) override;
		//void setRunType(RunType&&) override;
		void setRunType(RunType) override;
		wchar_t* getProcessName() override;
		wchar_t* getCommandLineArgs() override;
		wchar_t* getPassword() override;
		wchar_t* getUser() override;
		wchar_t* getDomain() override;
		RunType getRunType() override;
	};
#pragma endregion
	//TODO: IMPLEMENT!!!!!
#pragma region ASCII
	class ProcessRunDataA :
		IProcessRunData<LPSTR>
	{
	public:
		ProcessRunDataA() {};
		~ProcessRunDataA() {};
		/*void setProcessName(char*) override;
		void setCommandLineArgs(char*) override;
		void setPassword(char*) override;
		void setUser(char*) override;
		void setDomain(char*) override;
		void setRunType(RunType&&) override;
		void setRunType(RunType) override;
		char* getProcessName() override;
		char* getCommandLineArgs() override;
		char* getPassword() override;
		char* getUser() override;
		char* getDomain() override;
		RunType getRunType() override;*/
	};
#pragma endregion 
}

