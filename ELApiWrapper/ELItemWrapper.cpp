#include "ELItemWrapper.h"



ELItemWrapper::ELItemWrapper(pELItem item)
{
	this->_item = item;
}


ELItemWrapper::~ELItemWrapper()
{
	this->_item = NULL;
}

String^ ELItemWrapper::Name() {
	String^ clistr = gcnew System::String(this->_item->Name());

	return clistr;
}

WORD ELItemWrapper::Channel() {
	return this->_item->Channel();
}
