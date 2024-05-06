#pragma once
#include "..\Object\Entity.h"


class Ground : public Entity
{
public:
	Ground() = default;
	void Start() override;
	DECLARE_RTTI(Ground, Entity);
};

