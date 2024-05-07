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
	sf::FloatRect entityHitbox = Cast<RenderComponent>(obj->componentList.at("Render"))->spriteComp.getGlobalBounds();
	sf::FloatRect otherHitbox;
	collisionActive.clear();
	for(Entity* entity : EntityManager::GetInstance()->GetEntityList())
	{
		if (entityHitbox.intersects(Cast<RenderComponent>(entity->componentList.at("Render"))->spriteComp.getGlobalBounds()) && entity != obj)
		{
			otherHitbox = Cast<RenderComponent>(entity->componentList.at("Render"))->spriteComp.getGlobalBounds();
			if ((entityHitbox.top +entityHitbox.height) - otherHitbox.top <= 10 )
			{
				collisionActive.push_back("Down");
			}
			else if (entityHitbox.top - (otherHitbox.top + otherHitbox.height) >= -10)
			{
				collisionActive.push_back("Up");
			}
			else if ((entityHitbox.left + entityHitbox.width) - otherHitbox.left <= 30)
			{
				collisionActive.push_back("Right"); 
			}
			else if (entityHitbox.left - (otherHitbox.left + otherHitbox.width) >= -30)
			{
				collisionActive.push_back("Left");
			}
			
		}
	}
	std::cout << collisionActive.size() << std::endl;
	return collisionActive;
}
