#pragma once
#include "../ELPlugin/api.h"

public ref class ELItemTypeWrapper
{
public:
	ELItemTypeWrapper(pELGenericInfo type);
	ELItemTypeWrapper(pELItemType type);
	virtual ~ELItemTypeWrapper();
	pELItemType Get();

private:
	pELItemType _type;
};

