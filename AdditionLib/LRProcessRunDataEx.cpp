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
		this->processName = System::String::IsNullOrWhiteSpace(name->ToString()) ? nullptr : name;
	}
	void CLRProcessRunDataEx::setUser(StringBuilder ^ user)
	{
		this->user = System::String::IsNullOrWhiteSpace(user->ToString()) ? nullptr : user;
	}
	void CLRProcessRunDataEx::setCommandLineArgs(StringBuilder ^ args)
	{
		this->commandLineArgs = System::String::IsNullOrWhiteSpace(args->ToString()) ? nullptr : args;
		
	}
	void CLRProcessRunDataEx::setDomain(StringBuilder ^ domain)
	{
		this->domain = System::String::IsNullOrWhiteSpace(domain->ToString()) ? nullptr : domain;
	}
	void CLRProcessRunDataEx::setPassword(StringBuilder ^ pass)
	{
		this->password = System::String::IsNullOrWhiteSpace(pass->ToString()) ? nullptr : pass;

	}
	void CLRProcessRunDataEx::setType(StringBuilder ^ type)
	{
		this->type = System::String::IsNullOrWhiteSpace(type->ToString()) ? nullptr : type;
	}
	StringBuilder ^ CLRProcessRunDataEx::getProcessName()
	{
		return System::String::IsNullOrWhiteSpace(this->processName->ToString()) ? nullptr : this->processName;
	}
	StringBuilder ^ CLRProcessRunDataEx::getUser()
	{
		return System::String::IsNullOrWhiteSpace(this->user->ToString()) ? nullptr : this->user;
	}
	StringBuilder ^ CLRProcessRunDataEx::getCommandLineArgs()
	{
		return System::String::IsNullOrWhiteSpace(this->commandLineArgs->ToString()) ? nullptr : this->commandLineArgs;
	}
	StringBuilder ^ CLRProcessRunDataEx::getDomain()
	{
		return System::String::IsNullOrWhiteSpace(this->domain->ToString()) ? nullptr : this->domain;
	}
	StringBuilder ^ CLRProcessRunDataEx::getPassword()
	{
		return System::String::IsNullOrWhiteSpace(this->password->ToString()) ? nullptr : this->password;

	}
	StringBuilder ^ CLRProcessRunDataEx::getType()
	{
		return System::String::IsNullOrWhiteSpace(this->type->ToString()) ? nullptr : this->type;
	}
}
