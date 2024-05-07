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
	void checkCollision(std::vector<std::string> collisionActive);
	virtual ~PhysicManager();
	static PhysicManager* GetInstance();
	bool isOnGround = false;
	bool isJumping;
	bool canMoveR = true;
	bool canMoveL = true;
	bool canJump = true;
	int direction = 1;
	FVector2D velocity;
	std::vector<std::string> collisionActive;
	DECLARE_RTTI(PhysicManager, BaseObject);
private:
	static PhysicManager* m_physicsManager;
};





