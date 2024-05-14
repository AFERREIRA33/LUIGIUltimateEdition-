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

void PhysicManager::Update(Player* player, float deltaTime)
{
	isOnGround = false;
	canMoveR = true;
	canMoveL = true;
	canJump = true;
	collisionActive = Cast<ColliderComponent>(player->componentList.at("Collider"))->OnCollision();
	
	checkCollision(collisionActive);

	if (!isOnGround)
	{
		
		if (direction == -1)
		{
			velocity += 5 * deltaTime * 2;
			if (canMoveL)
			{
				player->ChangePosition(FVector2D(-velocity.x, velocity.y));
			}
			else
			{
				player->ChangePosition(FVector2D(0, velocity.y));

			}
			
		}
		else if (direction == 1)
		{
			velocity += 5 * deltaTime * 2;
			if (canMoveR)
			{
				player->ChangePosition(FVector2D(velocity.x, velocity.y));
			}
			else
			{
				player->ChangePosition(FVector2D(0, velocity.y));
			}
			
		}
		else {
			velocity.y += 5 * deltaTime * 2;
			player->ChangePosition(FVector2D(0, velocity.y));
		}
	}
	else
	{
		player->isJumping = false;
	}
	
}

void PhysicManager::AddForce()
{

	velocity.x = 0;
	velocity.y = -4;
}

void PhysicManager::checkCollision(std::vector<std::string> collisionActive)
{
	for (std::string col : collisionActive) {
		if (col == "Down")
		{
			isOnGround = true;
		}
		if (col == "Up")
		{
			canJump = false;
		}
		if (col == "Left")
		{
			canMoveL = false;
		}
		if (col == "Right")
		{
			canMoveR = false;
		}

	}
}

