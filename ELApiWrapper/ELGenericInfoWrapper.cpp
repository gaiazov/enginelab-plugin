#include "ELGenericInfoWrapper.h"



ELGenericInfoWrapper::ELGenericInfoWrapper(pELGenericInfo info)
{
	this->_info = info;
}


ELGenericInfoWrapper::~ELGenericInfoWrapper()
{
	this->_info = NULL;
}

pELGenericInfo ELGenericInfoWrapper::Get()
{
	return this->_info;
}