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

pELItem ELItemWrapper::Get() {
	return this->_item;
}

UINT ELItemWrapper::AddConstantChannel(WORD channel, float constant) {
	pELItemInputs inputs = this->_item->Header()->Inputs();

	return inputs->AddConstant(channel, constant);
}