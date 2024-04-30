#pragma once
#include "..\Object\Entity.h"

class Player : public Entity
{
public:
	Player() = default;
	void Start() override;
	void PlayerMove(float speed, float deltaTime);
	void PlayerJump();
	void Collide();


	DECLARE_RTTI(Player, Entity);
};

