#pragma once
#include "ICLRProcessRunData.h"
namespace AdditionLib
{
	ref class CLRProcessRunDataStr :
		public ICLRProcessRunData<System::String^>
	{
	public:
		CLRProcessRunDataStr();
		void setProcessName(System::String^ process) override;
		void setUser(System::String^ user) override;
	};
}

