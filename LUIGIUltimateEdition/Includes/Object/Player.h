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
	void Collide();
	void ChangePosition(FVector2D pos);

	bool isJumping;

	DECLARE_RTTI(Player, Entity);
};

