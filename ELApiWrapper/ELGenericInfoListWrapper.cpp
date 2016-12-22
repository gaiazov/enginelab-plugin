#include "ELGenericInfoListWrapper.h"



ELGenericInfoListWrapper::ELGenericInfoListWrapper(pELGenericInfoList list)
{
	this->_list = list;
}


ELGenericInfoListWrapper::~ELGenericInfoListWrapper()
{
	this->_list = NULL;
}

ELItemTypeWrapper^ ELGenericInfoListWrapper::InfoItemType(UINT index) {
	pELGenericInfo info = this->_list->Info(index);
	return gcnew ELItemTypeWrapper(info);
}