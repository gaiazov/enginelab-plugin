#pragma once
#include "../ELPlugin/api.h"
#include "ELItemTypeWrapper.h"
#include "ELItemWrapper.h"

using namespace System;

public ref class ELModelWrapper
{
public:
	ELModelWrapper(IntPtr model);
	virtual ~ELModelWrapper();

	DWORD NextAvailableChannelNumber();
	ELItemWrapper^ CreateNoop(String^ name, ELItemTypeWrapper^ type);

private:
	pELModeler _model;
};

