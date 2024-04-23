#pragma once

#include "SFML/Graphics.hpp"
#include "..\Components\BaseObject.h"

class PhysicManager : public BaseObject
{

public:
	PhysicManager();
	float Update(float deltaTime);
	virtual ~PhysicManager();
	static PhysicManager* GetInstance();
	bool isOnGround;
	bool isJumping;
	sf::Vector2f velocity;
	DECLARE_RTTI(PhysicManager, BaseObject);
private:
	static PhysicManager* m_physic;
};





