#pragma once
#include "../ELPlugin/api.h"
#include "ELModelWrapper.h"
#include "ELGenericInfoListWrapper.h"

using namespace System;

public ref class ELTargetWrapper
{
public:
	ELTargetWrapper(IntPtr target);
	virtual ~ELTargetWrapper();
	String^ GetName();
	DWORD InterfaceVersion();
	ELModelWrapper^ Modeler();
	ELGenericInfoListWrapper^ ELTargetWrapper::InfoList(TARGETINFO on);

private:
	pELTarget _target;
};