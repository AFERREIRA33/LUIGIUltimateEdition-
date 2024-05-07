#pragma once
#include "..\Object\Entity.h"

class Player : public Entity
{
public:
	Player() = default;
	virtual ~Player();
	void Start() override;
	void PlayerMove(float speed, float deltaTime);
	void PlayerJump(FVector2D velocity,float deltaTime);
	void Collide();
	bool isJumping;
	void Update();

	DECLARE_RTTI(Player, Entity);
};

