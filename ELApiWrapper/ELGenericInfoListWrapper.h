#pragma once
#include "../ELPlugin/api.h"
#include "ELGenericInfoWrapper.h"

using namespace System;

public ref class ELGenericInfoListWrapper
{
public:
	ELGenericInfoListWrapper(pELGenericInfoList list);
	virtual ~ELGenericInfoListWrapper();
	ELGenericInfoWrapper^ Info(UINT index);

private:
	pELGenericInfoList _list;
};

