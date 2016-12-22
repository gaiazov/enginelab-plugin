#include "ELTargetWrapper.h"

using namespace System;
using namespace System::Runtime::InteropServices;

ELTargetWrapper::ELTargetWrapper(IntPtr target)
{
	this->_target = (pELTarget)target.ToPointer();
}

ELTargetWrapper::~ELTargetWrapper()
{
	this->_target = NULL;
}

String^ ELTargetWrapper::GetName() {
	BYTE buff[0x1000] = { 0 };
	pELString strPtr = (pELString)buff;

	this->_target->GetName(&strPtr);

	String^ clistr = gcnew System::String(strPtr->str);
	
	return clistr;
}

DWORD ELTargetWrapper::InterfaceVersion()
{
	return this->_target->InterfaceVersion();
}

ELModelWrapper^ ELTargetWrapper::Modeler()
{
	pELModeler _model;
	DWORD status = this->_target->Modeler(&_model);
	if (status == DS_SUCCESS) {
		return gcnew ELModelWrapper((IntPtr)_model);
	}
	return nullptr;
}

ELGenericInfoListWrapper^ ELTargetWrapper::InfoList(TARGETINFO type) {
	pELGenericInfoList list = NULL;
	DWORD status = this->_target->InfoList(type, &list);
	if (status == DS_SUCCESS) {
		return gcnew ELGenericInfoListWrapper(list);
	}
	return nullptr;
}