#include "stdafx.h"
#include "NativeFunctionWrapper.h"


NativeFunctionWrapper::NativeFunctionWrapper()
{
}


NativeFunctionWrapper::~NativeFunctionWrapper()
{
}

bool NativeFunctionWrapper::runAsAnotherUser(MyMap map)
{
	return LogInAsUser(map);
}

bool NativeFunctionWrapper::runAsAnotherUserS(MyMap map)
{
	return LogInAsUser(map);
}

void NativeFunctionWrapper::msgbox(LPCWSTR str)
{
 	MsgBx(str);
}

bool NativeFunctionWrapper::runAsAnotherUserS(std::shared_ptr<Logon::ProcessRunDataW> data)
{
	return false;
}
