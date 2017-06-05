#include "stdafx.h"
#include "LRProcessRunDataStr.h"

namespace AdditionLib
{
	CLRProcessRunDataStr::CLRProcessRunDataStr()
	{
	}

	void CLRProcessRunDataStr::setProcessName(System::String^ process)
	{
		this->processName = process;
	}

	void CLRProcessRunDataStr::setUser(System::String^ user)
	{
		this->user = user;
	}

}
