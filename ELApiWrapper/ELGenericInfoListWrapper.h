#pragma once
#include "../ELPlugin/api.h"
#include "ELItemTypeWrapper.h"

using namespace System;

public ref class ELGenericInfoListWrapper
{
public:
	ELGenericInfoListWrapper(pELGenericInfoList list);
	virtual ~ELGenericInfoListWrapper();
	ELItemTypeWrapper^ InfoItemType(UINT index);

private:
	pELGenericInfoList _list;
};

