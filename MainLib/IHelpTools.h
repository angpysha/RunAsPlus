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
};

