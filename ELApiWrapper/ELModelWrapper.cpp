#include "ELModelWrapper.h"

using namespace System;
using namespace System::Runtime::InteropServices;

ELModelWrapper::ELModelWrapper(IntPtr model)
{
	this->_model = (pELModeler)model.ToPointer();
}

ELModelWrapper::~ELModelWrapper()
{
	this->_model = NULL;
}

DWORD ELModelWrapper::NextAvailableChannelNumber()
{
	return this->_model->NextAvailableChannelNumber();
}

ELItemWrapper^ ELModelWrapper::CreateNoop(String^ name, ELGenericInfoWrapper^ type) {
	pELNoOperationItem item = NULL;

	IntPtr nameStrPtr = Marshal::StringToHGlobalAnsi(name);
	char* nameStr = static_cast<char*>(nameStrPtr.ToPointer());

	pELGenericInfo pType = type->Get(); //ITEMTYPE_NONE

	DWORD status = this->_model->NewItem((pELItemType)pType, nameStr, (pELItem*)&item);
	if (status == DS_SUCCESS) {
		status = this->_model->CreateItem(item, NULL);
		if (status == DS_SUCCESS) {
			return gcnew ELItemWrapper(item);
		}
		return nullptr;
	}
	return nullptr;
}

ELItemWrapper^ ELModelWrapper::CreateThermistor(String^ name, ELGenericInfoWrapper^ type, ELGenericInfoWrapper^ outputType) {
	pELItem item = NULL;

	IntPtr nameStrPtr = Marshal::StringToHGlobalAnsi(name);
	char* nameStr = static_cast<char*>(nameStrPtr.ToPointer());

	pELGenericInfo pType = type->Get(); //ITEMTYPE_THERMISTOR
	pELGenericInfo info = outputType->Get();
	const char* thermistor_name = info->Name();

	DWORD status = this->_model->NewItem((pELItemType)pType, nameStr, (pELItem*)&item);
	if (status == DS_SUCCESS) {
		pELItemInputs inputs = item->Header()->Inputs();

		inputs->AddConstant(0, 1234);
		inputs->AddConstant(0, 2490);
		
		status = this->_model->CreateItem(item, NULL);
		if (status == DS_SUCCESS) {
			return gcnew ELItemWrapper(item);
		}
		return nullptr;
	}
	return nullptr;
}