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
	ELItemWrapper^ CreateNoop(String^ name, ELGenericInfoWrapper^ type);
	ELItemWrapper^ CreateThermistor(String^ name, ELGenericInfoWrapper^ type, ELGenericInfoWrapper^ outputType);

private:
	pELModeler _model;
};

