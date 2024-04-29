#pragma once
#include "..\..\Includes\Manager\PhysicManager.h"

PhysicManager* PhysicManager::m_physicsManager = nullptr;

PhysicManager* PhysicManager::GetInstance() {
	if (m_physicsManager == nullptr)
	{
		m_physicsManager = new PhysicManager();
	}
	return m_physicsManager;
}



PhysicManager::~PhysicManager()
{
	delete m_physicsManager;
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

