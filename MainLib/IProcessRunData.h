#pragma once
enum class RunType : int
{
	User=0,
	Token=1
};
template <typename T> class IProcessRunData
{
public:
	IProcessRunData() {};
	virtual ~IProcessRunData() {};
	virtual void setProcessName(T) = 0;
	virtual void setCommandLineArgs(T) = 0;
	virtual void setPassword(T) = 0;
	virtual void setUser(T) = 0;
	virtual void setDomain(T) = 0;
	//virtual void setRunType(RunType&&) = 0;
	virtual void setRunType(RunType) = 0;
	virtual T getProcessName() = 0;
	virtual T getCommandLineArgs() = 0;
	virtual T getPassword() = 0;
	virtual T getUser() = 0;
	virtual T getDomain() = 0;
	virtual RunType getRunType() = 0;
protected:
	T processName = nullptr;
	T commandLineArgs = nullptr;
	T password = nullptr;
	T user = nullptr;
	T domain = nullptr;
	RunType run_type;
};

