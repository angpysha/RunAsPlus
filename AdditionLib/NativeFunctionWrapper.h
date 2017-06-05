#pragma once
#include <MainLib.h>
#include <Windows.h>

#pragma unmanaged
class NativeFunctionWrapper
{
public:
	NativeFunctionWrapper();
	~NativeFunctionWrapper();
	bool runAsAnotherUser(MyMap map);
	// serialize()
	static bool runAsAnotherUserS(MyMap map);
	static bool runAsAnotherUserS(std::shared_ptr<Logon::ProcessRunDataW> data);
	static void msgbox(LPCWSTR str);
};

