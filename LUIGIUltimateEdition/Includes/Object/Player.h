#pragma once

#include "..\..\Includes\Object\Entity.h"

class Player : public Entity
{
	Player();
	void Start() override;
	void PlayerMove();
	void PlayerJump();
	void Collide();


	DECLARE_RTTI(Player, Entity);
};

