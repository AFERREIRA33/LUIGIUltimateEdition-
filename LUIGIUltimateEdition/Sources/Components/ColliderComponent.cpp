#pragma once
#include "..\..\Includes\Components\ColliderComponent.h"
#include "..\..\Includes\Object\Player.h"
#include "..\..\Includes\Object\Ground.h"
#include "..\..\Includes\Manager\EntityManager.h"
#include "..\..\Includes\Object\Entity.h"

ColliderComponent* ColliderComponent::collider = nullptr;

ColliderComponent::~ColliderComponent()
{
	delete collider;
}

std::vector<std::string> ColliderComponent::OnCollision()
{
	entityHitbox = Cast<RenderComponent>(obj->componentList.at("Render"))->spriteComp.getGlobalBounds();
	// entityhitbox is the hitbox of the actual entity
	collisionActive.clear();
	for(Entity* entity : EntityManager::GetInstance()->GetEntityList())
	{
		if (entityHitbox.intersects(Cast<RenderComponent>(entity->componentList.at("Render"))->spriteComp.getGlobalBounds()) && entity != obj && entity->Tag != "BackGround")
		{
			otherHitbox = Cast<RenderComponent>(entity->componentList.at("Render"))->spriteComp.getGlobalBounds();
			if ((entityHitbox.top + entityHitbox.height) - otherHitbox.top <= 10 )
			{
				// if the distance between the bottom of the actual entity and the top of the other entity is less or equal to 10, then they collide at the downward
				collisionActive.push_back("Down");
			}
			else if (entityHitbox.top - (otherHitbox.top + otherHitbox.height) >= -10)
			{
				// if the distance between the top of the actual entity and the bottom of the other entity is more or equal to -10, then they collide at the upward
				collisionActive.push_back("Up");
			}
			else if ((entityHitbox.left + entityHitbox.width) - otherHitbox.left <= 30)
			{
				// if the distance between the right side of the actual entity and the left side of the other entity is less or equal to 30, then they collide on the right
				collisionActive.push_back("Right"); 
			}
			else if (entityHitbox.left - (otherHitbox.left + otherHitbox.width) >= -30)
			{
				// if the distance between the left side of the actual entity and the right side of the other is more or equal to -30, then they collide on the left
				collisionActive.push_back("Left");
			}
			
		}
	}
	return collisionActive;
}
