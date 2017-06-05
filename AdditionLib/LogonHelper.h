#pragma once
using namespace System;
using namespace System::Collections::Generic;

#pragma managed
namespace Logon
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
	public ref class LogonHelper
	{
	public:
		LogonHelper();
		System::Boolean runAsAnotherUser(Dictionary<MPData, System::String^> ^dict);
		void MsgBx(System::String ^str);
		System::Boolean runAsAnotherUser();
	private:
		/*PData MPData2PData(MPData);
		PData MPData2PDataEx(MPData);*/
	};
}

