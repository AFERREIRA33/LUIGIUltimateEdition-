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

bool ColliderComponent::OnCollision()
{
	sf::FloatRect entityHitbox = Cast<RenderComponent>(obj->componentList.at("Render"))->spriteComp.getGlobalBounds();
	sf::FloatRect otherHitbox;
	for(Entity* entity : EntityManager::GetInstance()->GetEntityList())
	{
		if (entityHitbox.intersects(Cast<RenderComponent>(entity->componentList.at("Render"))->spriteComp.getGlobalBounds()) && entity != obj)
		{
			otherHitbox = Cast<RenderComponent>(entity->componentList.at("Render"))->spriteComp.getGlobalBounds();
			if ((entityHitbox.top +entityHitbox.height) - otherHitbox.top <= 10 )
			{
				return true;
			}
			else if (entityHitbox.top - (otherHitbox.top + otherHitbox.height) >= -10)
			{
				return true;
			}
			else if ((entityHitbox.left + entityHitbox.width) - otherHitbox.left <= 10)
			{
				return true;
			}
			else if (entityHitbox.left - (otherHitbox.left + otherHitbox.width) >= -10)
			{
				return true;
			}
			
		}
	}

	return false;
}
