#pragma once
namespace AdditionLib
{
	generic <class T>
		public ref class ICLRProcessRunData abstract
		{
		public:
			ICLRProcessRunData();
			virtual ~ICLRProcessRunData();
			virtual void setProcessName(T name) = 0;
			virtual void setUser(T user) = 0;
			virtual void setCommandLineArgs(T args) = 0;
			virtual void setDomain(T domain) = 0;
			virtual void setPassword(T pass) = 0;
			virtual void setType(T type) = 0;
			virtual T getProcessName() = 0;
			virtual T getUser() = 0;
			virtual T getCommandLineArgs() = 0;
			virtual T getDomain() = 0;
			virtual T getPassword() = 0;
			virtual T getType() = 0;
		protected:
			T processName;
			T user;
			T commandLineArgs;
			T domain;
			T password;
			T type;
		};
}

