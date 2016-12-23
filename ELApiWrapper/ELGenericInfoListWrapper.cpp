#include "ELGenericInfoListWrapper.h"

ELGenericInfoListWrapper::ELGenericInfoListWrapper(pELGenericInfoList list)
{
	this->_list = list;
}

ELGenericInfoListWrapper::~ELGenericInfoListWrapper()
{
	this->_list = NULL;
}

ELGenericInfoWrapper^ ELGenericInfoListWrapper::Info(UINT index) {
	pELGenericInfo info = this->_list->Info(index);
	return gcnew ELGenericInfoWrapper(info);
}