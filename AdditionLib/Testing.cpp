#include "stdafx.h"
#include "Testing.h"
#ifdef _DEBUG

#include <string>
#include "LogonHelper.h"
#include "LRProcessRunData.h"
Testing::Testing()
{
}

void Testing::tstMsg(System::String ^ sss)
{
	cli::pin_ptr<const wchar_t> ff = PtrToStringChars(sss);
	LPWSTR  ffff = const_cast<LPWSTR>(ff);
	MessageBox(NULL, ffff, ffff, 0);
}
void Testing::tstMsgg(System::String^ sss, [Out] System::String^% rr)
{
	cli::pin_ptr<const wchar_t> fff = PtrToStringChars(sss);
	RunType tmp = static_cast<RunType>(std::stoi(fff));
	int aa = int(tmp);
	rr = aa.ToString();
	
}
#endif
