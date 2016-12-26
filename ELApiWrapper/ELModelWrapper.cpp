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

DWORD ELModelWrapper::CreateItem(ELItemWrapper^ item) {
	return this->_model->CreateItem(item->Get(), NULL);
}


ELItemWrapper^ ELModelWrapper::NewItem(String^ name, ELGenericInfoWrapper^ type) {
	pELItem item = NULL;

	IntPtr nameStrPtr = Marshal::StringToHGlobalAnsi(name);
	char* nameStr = static_cast<char*>(nameStrPtr.ToPointer());

	pELGenericInfo pType = type->Get();

	DWORD status = this->_model->NewItem((pELItemType)pType, nameStr, (pELItem*)&item);
	if (status == DS_SUCCESS) {
		return gcnew ELItemWrapper(item);
	}
	return nullptr;
}