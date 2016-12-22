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

ELItemWrapper^ ELModelWrapper::CreateNoop(String^ name, ELItemTypeWrapper^ type) {
	pELNoOperationItem item = NULL;

	IntPtr nameStrPtr = Marshal::StringToHGlobalAnsi(name);
	char* nameStr = static_cast<char*>(nameStrPtr.ToPointer());

	pELItemType pType = type->Get(); //ITEMTYPE_NONE

	DWORD status = this->_model->NewItem(pType, nameStr, (pELItem*)&item);
	if (status == DS_SUCCESS) {
		status = this->_model->CreateItem(item, NULL);
		if (status == DS_SUCCESS) {
			return gcnew ELItemWrapper(item);
		}
		return nullptr;
	}
	return nullptr;
}