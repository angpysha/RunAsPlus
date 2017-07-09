#include "stdafx.h"
#include "LRProcessRunData.h"
#include <vcclr.h>
#include <string>
#include "LogonHelper.h"
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
	/*
	 Converts this class to same unmanaged model. NOT USE THIS METHOD AT C#!!!
	 */
	std::shared_ptr<Logon::ProcessRunData> CLRProcessRunData::toUnmanaged()
	{
		std::shared_ptr<Logon::ProcessRunData> uData = std::make_shared<Logon::ProcessRunData>();
		/*
		 *     pin_ptr<const wchar_t> wname = PtrToStringChars(s);
				FindFirstFile(wname, &data);
				System::String ^str = "Hello World";
				
				IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);

				HANDLE hFind = FindFirstFile((LPCSTR)ptr.ToPointer(), data);

				System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
		 */
		cli::pin_ptr<const wchar_t> lwcProcessName = PtrToStringChars(this->processName);
		/*LPWSTR lwProcessName = const_cast<LPWSTR>(lwcProcessName);*/
		uData->setUser(const_cast<LPWSTR>(lwcProcessName));

		cli::pin_ptr<const wchar_t> lwcUser = PtrToStringChars(this->user);
		cli::pin_ptr<const wchar_t> lwcDomain = PtrToStringChars(this->domain);
		cli::pin_ptr<const wchar_t> lwcPassword = PtrToStringChars(this->password);
		cli::pin_ptr<const wchar_t> lwcArgs = PtrToStringChars(this->commandLineArgs);
		cli::pin_ptr<const wchar_t> lwcType = PtrToStringChars(this->type);

		uData->setUser(const_cast<LPWSTR>(lwcUser));
		uData->setDomain(const_cast<LPWSTR>(lwcDomain));
		uData->setPassword(const_cast<LPWSTR>(lwcPassword));
		if (this->type != nullptr)
		uData->setCommandLineArgs(const_cast<LPWSTR>(lwcArgs));

		 //MLogon::MPType tmp = static_cast<MLogon::MPType>(std::stoi(lwcType));
	//	if (this->type != nullptr)
	//	RunType tmp = static_cast<RunType>(std::stoi(lwcType));
		//uData->setRunType(tmp);
		return uData;
		//return std::shared_ptr<Logon::ProcessRunData>();
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
