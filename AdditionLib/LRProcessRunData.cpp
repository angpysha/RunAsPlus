#include "stdafx.h"
#include "LRProcessRunData.h"
namespace AdditionLib
{

	CLRProcessRunData::CLRProcessRunData()
	{
		this->user = nullptr;
		this->domain = nullptr;
		this->password = nullptr;
		this->processName = nullptr;
		this->commandLineArgs = nullptr;
	}
	std::shared_ptr<Logon::ProcessRunData> CLRProcessRunData::toUnmanaged()
	{
		std::shared_ptr<Logon::ProcessRunData> uData = std::make_shared<Logon::ProcessRunData>();
		return std::shared_ptr<Logon::ProcessRunData>();
	}
	void CLRProcessRunData::setProcessName(System::String ^ name)
	{
		this->processName = System::String::IsNullOrWhiteSpace(name) ? nullptr : name;
	}
	void CLRProcessRunData::setUser(System::String ^ user)
	{
		this->user = System::String::IsNullOrWhiteSpace(user) ? nullptr : user;
	}
	void CLRProcessRunData::setCommandLineArgs(System::String ^ args)
	{
		this->commandLineArgs = System::String::IsNullOrWhiteSpace(args) ? nullptr : user;
	}
	void CLRProcessRunData::setDomain(System::String ^ domain)
	{
		this->domain = System::String::IsNullOrWhiteSpace(domain) ? nullptr : domain;
	}
	void CLRProcessRunData::setPassword(System::String ^ pass)
	{
		this->password = System::String::IsNullOrWhiteSpace(pass) ? nullptr : pass;
	}
	void CLRProcessRunData::setType(System::String ^ type)
	{
		this->type = System::String::IsNullOrWhiteSpace(type) ? nullptr : type;
	}
	System::String ^ CLRProcessRunData::getProcessName()
	{
		return (System::String::IsNullOrWhiteSpace(this->processName) ? nullptr : this->processName);
	}
	System::String ^ CLRProcessRunData::getUser()
	{
		return (System::String::IsNullOrWhiteSpace(this->user) ? nullptr : this->user);
	}
	System::String ^ CLRProcessRunData::getCommandLineArgs()
	{
		return (System::String::IsNullOrWhiteSpace(this->commandLineArgs) ? nullptr : this->commandLineArgs);

	}
	System::String ^ CLRProcessRunData::getDomain()
	{
		return (System::String::IsNullOrWhiteSpace(this->domain) ? nullptr : this->domain);

	}
	System::String ^ CLRProcessRunData::getPassword()
	{
		return (System::String::IsNullOrWhiteSpace(this->password) ? nullptr : this->password);

	}
	System::String ^ CLRProcessRunData::getType()
	{
		return (System::String::IsNullOrWhiteSpace(this->type) ? nullptr : this->type);
	}
	/*CLRProcessRunData::~ICLRProcessRunData()
	{
		
	}*/
}
