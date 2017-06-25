#include "stdafx.h"
#include <msclr/marshal_cppstd.h>
#include "LogonHelper.h"
#include "MainLib.h"
#pragma unmanaged
#include "NativeFunctionWrapper.h"
#pragma managed
namespace MLogon
{
	LogonHelper::LogonHelper()
	{

	}

	System::Boolean LogonHelper::runAsAnotherUser(Dictionary<MPData, System::String^> ^dict)
	{
		/*MyMap myMap;
		PData pdata{};
		Int32 enV = (Int32)*/
		//dict[MPData::user];
		MyMap map{};
		//	map.left.find(PData::user)->second = (const std::wstring)msclr::interop::marshal_as<std::wstring>(dict[MPData::user]);
		//	map.left.insert(PData::user, msclr::interop::marshal_as<std::wstring>(dict[MPData::user]));
		map.insert(MyMap::value_type(PData::user, msclr::interop::marshal_as<std::wstring>(dict[MPData::user])));
		map.insert(MyMap::value_type(PData::domain, msclr::interop::marshal_as<std::wstring>(dict[MPData::domain])));
		map.insert(MyMap::value_type(PData::password, msclr::interop::marshal_as<std::wstring>(dict[MPData::password])));
		map.insert(MyMap::value_type(PData::processName, msclr::interop::marshal_as<std::wstring>(dict[MPData::processName])));
		map.insert(MyMap::value_type(PData::commandLineArgs, msclr::interop::marshal_as<std::wstring>(dict[MPData::commandLineArgs])));
		map.insert(MyMap::value_type(PData::type, msclr::interop::marshal_as<std::wstring>(dict[MPData::type])));
		//std::shared_ptr<NativeFunctionWrapper> wrapper{};
		//NativeFunctionWrapper* wrapper = new NativeFunctionWrapper();
		return NativeFunctionWrapper::runAsAnotherUserS(map);
	//	return false;
	}

	void LogonHelper::MsgBx(System::String ^str)
	{
		//LPCWSTR str2 = msclr::interop::marshal_as<std::wstring>(str).c_str();
		LPCWSTR ff = (LPCWSTR)(Runtime::InteropServices::Marshal::StringToHGlobalUni(str)).ToPointer();
		NativeFunctionWrapper::msgbox(ff);

	}

	System::Boolean LogonHelper::runAsAnotherUser()
	{
		return false;
	}
}





