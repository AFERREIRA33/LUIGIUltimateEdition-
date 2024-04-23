#pragma once

#include "SFML/Graphics.hpp"

class PhysicManager
{

public:
	PhysicManager();
	float Update(float deltaTime);
	virtual ~PhysicManager();
	static PhysicManager* GetInstance();
	bool isOnGround;
	bool isJumping;
	sf::Vector2f velocity;
	

private:
	static PhysicManager* m_physic;
};





