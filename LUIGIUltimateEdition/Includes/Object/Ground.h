#pragma once
#include "..\Object\Entity.h"


class Ground : public Entity
{
public:
	Ground() = default;
	void Start(float x, float y) override;
	DECLARE_RTTI(Ground, Entity);
};

