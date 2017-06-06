#pragma once
#include "ICLRProcessRunData.h"
#include <memory>
#include <LogonTools.h>
#include <ProcessRunData.h>
using namespace System::Text;
namespace AdditionLib
{
#pragma managed
	ref class CLRProcessRunDataEx :
		public ICLRProcessRunData<System::Text::StringBuilder^>
	{
	public:
		CLRProcessRunDataEx();
		std::shared_ptr<Logon::ProcessRunData> toUnmanaged();
		void setProcessName(StringBuilder^ name) override;
		void setUser(StringBuilder^ user) override;
		void setCommandLineArgs(StringBuilder^ args) override;
		void setDomain(StringBuilder^ domain) override;
		void setPassword(StringBuilder^ pass) override;
		void setType(StringBuilder^ type) override;
	};
}

