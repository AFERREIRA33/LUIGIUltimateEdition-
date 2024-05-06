#pragma once

#include "..\Components\BaseObject.h"
#include "..\Utils\Vector2D.h"

class Player;
class Ground;


class PhysicManager : public BaseObject
{

public:
	PhysicManager();
	void Update(Player* player, Ground* ground, float deltaTime);
	void AddForce();
	virtual ~PhysicManager();
	static PhysicManager* GetInstance();
	bool isOnGround;
	bool isJumping;
	bool direction;
	FVector2D velocity;
	DECLARE_RTTI(PhysicManager, BaseObject);
private:
	static PhysicManager* m_physicsManager;
};





