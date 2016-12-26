#pragma once
#include "../ELPlugin/api.h"
#include "ELItemWrapper.h"
#include "ELGenericInfoWrapper.h"

using namespace System;

public ref class ELModelWrapper
{
public:
	ELModelWrapper(IntPtr model);
	virtual ~ELModelWrapper();

	DWORD NextAvailableChannelNumber();

	DWORD CreateItem(ELItemWrapper^ item);
	ELItemWrapper^ NewItem(String^ name, ELGenericInfoWrapper^ type);

private:
	pELModeler _model;
};

