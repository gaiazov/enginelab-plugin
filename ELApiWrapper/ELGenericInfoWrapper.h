#pragma once
#include "../ELPlugin/api.h"

public ref class ELGenericInfoWrapper
{
public:
	ELGenericInfoWrapper(pELGenericInfo info);
	virtual ~ELGenericInfoWrapper();
	pELGenericInfo Get();

private:
	pELGenericInfo _info;
};

