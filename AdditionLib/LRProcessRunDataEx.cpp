#include "stdafx.h"
#include "LRProcessRunDataEx.h"
namespace AdditionLib
{

	CLRProcessRunDataEx::CLRProcessRunDataEx()
	{
	}
	std::shared_ptr<Logon::ProcessRunData> CLRProcessRunDataEx::toUnmanaged()
	{
		std::shared_ptr<Logon::ProcessRunData> dataa = std::make_shared<Logon::ProcessRunData>();
		return std::shared_ptr<Logon::ProcessRunData>();
	}
	void CLRProcessRunDataEx::setProcessName(StringBuilder ^ name)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRProcessRunDataEx::setUser(StringBuilder ^ user)
	{
		
		throw gcnew System::NotImplementedException();
	}
	void CLRProcessRunDataEx::setCommandLineArgs(StringBuilder ^ args)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRProcessRunDataEx::setDomain(StringBuilder ^ domain)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRProcessRunDataEx::setPassword(StringBuilder ^ pass)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRProcessRunDataEx::setType(StringBuilder ^ type)
	{
		throw gcnew System::NotImplementedException();
	}
}
