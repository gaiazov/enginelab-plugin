#include "ELItemTypeWrapper.h"

ELItemTypeWrapper::ELItemTypeWrapper(pELGenericInfo type)
{
	this->_type = (pELItemType)type;
}


ELItemTypeWrapper::ELItemTypeWrapper(pELItemType type)
{
	this->_type = type;
}


ELItemTypeWrapper::~ELItemTypeWrapper()
{
	this->_type = NULL;
}

pELItemType ELItemTypeWrapper::Get() {
	return this->_type;
}