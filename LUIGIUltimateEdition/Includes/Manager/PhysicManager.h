#pragma once

#include "..\Components\BaseObject.h"
#include "..\Utils\Vector2D.h"


class PhysicManager : public BaseObject
{

public:
	PhysicManager();
	float Update(float deltaTime);
	virtual ~PhysicManager();
	static PhysicManager* GetInstance();
	bool isOnGround;
	bool isJumping;
	FVector2D velocity;
	DECLARE_RTTI(PhysicManager, BaseObject);
private:
	static PhysicManager* m_physic;
};





