#pragma once
#pragma managed

#ifdef _DEBUG
//#include "stdafx.h"
#include <vcclr.h>
#include <Windows.h>
using namespace System::Runtime::InteropServices;
public ref class Testing
{

public:
	Testing();
	void tstMsg(System::String^ sss);
	void tstMsgg(System::String^ sss,[Out] System::String^% rr);
};
#endif

