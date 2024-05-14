#pragma once
#include "..\Object\Entity.h"

class Player : public Entity
{
public:
	Player() = default;
	virtual ~Player();
	void Start(float x, float y) override;
	void Update();
	void PlayerMove(float speed, float deltaTime);
	void PlayerJump(FVector2D velocity,float deltaTime);
	void ChangePosition(FVector2D pos);
	void Death();

	bool isJumping;

	DECLARE_RTTI(Player, Entity);
};

