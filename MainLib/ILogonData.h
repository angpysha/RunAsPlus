#pragma once
template <typename T> class ILogonData
{
public:

	ILogonData()
	{
	}

	virtual ~ILogonData()
	{
	}

protected:
	T username;
	T password;
	T domain; 
};

