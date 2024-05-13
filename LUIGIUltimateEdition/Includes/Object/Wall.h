#pragma once
#include "..\Object\Entity.h"

class Wall : public Entity
{
public:
	Wall() = default;
	void Start() override;
	DECLARE_RTTI(Wall, Entity);
};

