#pragma once
#include "ICLRProcessRunData.h"
#pragma managed
namespace AdditionLib
{
	public ref class CLRProcessRunData :
		ICLRProcessRunData<System::String^>
	{
	public:
		CLRProcessRunData();
	};
}

