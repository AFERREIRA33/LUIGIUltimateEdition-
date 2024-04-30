#pragma once

#include "..\..\Includes\Object\Entity.h"

class Player : public Entity
{
public:
	Player() = default;
	void Start() override;
	void PlayerMove();
	void PlayerJump();
	void Collide();


	DECLARE_RTTI(Player, Entity);
};

