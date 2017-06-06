#pragma once
#include "ICLRProcessRunData.h"
#include <memory>
#include <Windows.h>
#include <ProcessRunData.h>
#pragma managed
namespace AdditionLib
{
	public ref class CLRProcessRunData :
		public ICLRProcessRunData<System::String^>
	{
	public:
		CLRProcessRunData();
		std::shared_ptr<Logon::ProcessRunData> toUnmanaged();
		//~ICLRProcessRunData() override;
		void setProcessName(System::String^ name) override;
		void setUser(System::String^ user) override;
		void setCommandLineArgs(System::String^ args) override;
		void setDomain(System::String^ domain) override;
		void setPassword(System::String^ pass) override;
		void setType(System::String^ type) override;
		System::String^ getProcessName() override;
		System::String^ getUser() override;
		System::String^ getCommandLineArgs() override;
		System::String^ getDomain() override;
		System::String^ getPassword() override;
		System::String^ getType() override;
	private:
		//friend std::shared_ptr<Logon::ProcessRunData> toUnmanaged ()
	};
}

