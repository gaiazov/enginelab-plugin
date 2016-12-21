#pragma once
#include "../ELPlugin/api.h"
#include "ELModelWrapper.h"

using namespace System;

public ref class ELTargetWrapper
{
public:
	ELTargetWrapper(IntPtr target);
	virtual ~ELTargetWrapper();
	String^ GetName();
	DWORD InterfaceVersion();
	ELModelWrapper^ Modeler();

private:
	pELTarget _target;
};