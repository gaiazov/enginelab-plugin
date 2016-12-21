#include "ELModelWrapper.h"

using namespace System;

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
