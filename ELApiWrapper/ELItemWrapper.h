#pragma once
#include "../ELPlugin/api.h"

using namespace System;

public ref class ELItemWrapper
{
public:
	ELItemWrapper(pELItem item);
	virtual ~ELItemWrapper();

	String^ Name();
	WORD Channel();

	pELItem Get();
	UINT ELItemWrapper::AddConstantChannel(WORD channel, float constant);

private:
	pELItem _item;
};

