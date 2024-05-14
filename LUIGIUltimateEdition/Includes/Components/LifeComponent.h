#pragma once
#include "..\Components\Component.h"

class LifeComponent : public Component
{
public:
	LifeComponent() = default;
	virtual ~LifeComponent();
	int life;
	DECLARE_RTTI(LifeComponent, Component);


};

