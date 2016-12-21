#pragma once
#include "../ELPlugin/api.h"

using namespace System;

public ref class ELModelWrapper
{
public:
	ELModelWrapper(IntPtr model);
	virtual ~ELModelWrapper();

	DWORD NextAvailableChannelNumber();

private:
	pELModeler _model;
};

