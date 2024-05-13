#pragma once
#include "..\Object\Entity.h"

class Wall : public Entity
{
public:
	Wall() = default;
	void Start(float x, float y) override;
	DECLARE_RTTI(Wall, Entity);
};

