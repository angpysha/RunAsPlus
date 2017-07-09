#pragma once
#include "LRProcessRunData.h"
using namespace System;
using namespace System::Collections::Generic;

#pragma managed
namespace MLogon
{
	public enum class MPData : int
	{
		processName = 0,
		commandLineArgs = 1,
		password = 2,
		user = 3,
		domain = 4,
		type = 5
	};

	public enum class MPType : int 
	{
		User = 0,
		Token =1
	};
	public ref class LogonHelper
	{
	public:
		LogonHelper();
		System::Boolean runAsAnotherUser(Dictionary<MPData, System::String^> ^dict);
		System::Boolean runAsAnotherUser(AdditionLib::CLRProcessRunData ^data);
		void MsgBx(System::String ^str);
		System::Boolean runAsAnotherUser();
	private:
		/*PData MPData2PData(MPData);
		PData MPData2PDataEx(MPData);*/
	};
}

