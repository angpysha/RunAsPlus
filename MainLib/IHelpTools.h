#pragma once

#include <Windows.h>

template <typename T> class  IHelpTools
{
public:

	IHelpTools()
	{
		
	}

	virtual ~IHelpTools()
	{
	}

	 virtual BOOL isStringNullOrWhiteSpace(T)=0;
	 virtual HANDLE GetProcessHandleByName(T) = 0;
};

