#include "stdafx.h"
#include "ProcessRunData.h"
#include "HelpTools.h"

namespace Logon
{

	ProcessRunDataW::ProcessRunDataW()
	{
	}


	ProcessRunDataW::~ProcessRunDataW()
	{
		this->processName = nullptr;
		this->commandLineArgs = nullptr;
		this->user = nullptr;
		this->password = nullptr;
		this->domain = nullptr;
		//this->run_type = NULL;
	}

	void ProcessRunDataW::setProcessName(LPWSTR name)
	{
		
		this->processName = (HelpTools::isStringNullOrWhitespace(name))?nullptr:name;
	}

	void ProcessRunDataW::setCommandLineArgs(LPWSTR args)
	{
		this->commandLineArgs = HelpTools::isStringNullOrWhitespace(args)?nullptr:args;
	}

	void ProcessRunDataW::setPassword(LPWSTR pass)
	{
		this->password = HelpTools::isStringNullOrWhitespace(pass)?nullptr:pass;
	}

	void ProcessRunDataW::setUser(LPWSTR user)
	{
		this->user = HelpTools::isStringNullOrWhitespace(user)?nullptr:user;
	}

	void ProcessRunDataW::setDomain(LPWSTR domain)
	{
		this->domain = HelpTools::isStringNullOrWhitespace(domain)?nullptr:domain;
	}

	/*void ProcessRunDataW::setRunType(RunType&& type)
	{
		this->run_type = type;
	}*/

	void ProcessRunDataW::setRunType(RunType type)
	{
		this->run_type = type;
	}

	wchar_t* ProcessRunDataW::getProcessName()
	{
		return (this->processName!=nullptr)?this->processName:L"";
	}

	wchar_t* ProcessRunDataW::getCommandLineArgs()
	{
		return (this->commandLineArgs!=nullptr)?this->commandLineArgs:NULL;
	}

	wchar_t* ProcessRunDataW::getPassword()
	{
		return (this->password!=nullptr)?this->password:L"";
	}

	wchar_t* ProcessRunDataW::getUser()
	{
		return (this->user!=nullptr)?this->user:L"";
	}

	wchar_t* ProcessRunDataW::getDomain()
	{
		return (this->domain != nullptr)? this->domain:L"";
	}

	RunType ProcessRunDataW::getRunType()
	{
		return this->run_type;
	}
}
