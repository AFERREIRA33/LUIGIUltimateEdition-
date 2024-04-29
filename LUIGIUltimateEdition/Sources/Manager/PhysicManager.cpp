#include "..\..\Includes\Manager\PhysicManager.h"

PhysicManager* PhysicManager::m_physic = nullptr;

PhysicManager* PhysicManager::GetInstance() {
	if (m_physic == nullptr)
	{
		m_physic = new PhysicManager();
	}
	return m_physic;
}



PhysicManager::~PhysicManager()
{
	delete m_physic;
}


PhysicManager::PhysicManager()
{
}

float PhysicManager::Update(float deltaTime)
{
	isOnGround = false;
	if (!isOnGround)
	{
		velocity.y += 9.81 * deltaTime * 2;
	}
	return velocity.y;
}

