#pragma once
#include "..\..\Includes\Manager\PhysicManager.h"
#include "..\..\Includes\Object\Player.h"
#include "..\..\Includes\Object\Ground.h"

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

void PhysicManager::Update(Player& player, Ground& ground, float deltaTime)
{
	isOnGround = Cast<ColliderComponent>(player.componentList.at("Collider"))->OnCollision(player,ground);
	if (!isOnGround)
	{
		velocity.y += 9.81 * deltaTime * 2;
		Cast<RenderComponent>(player.componentList.at("Render"))->spriteComp.move(0, velocity.y);
	}
}

