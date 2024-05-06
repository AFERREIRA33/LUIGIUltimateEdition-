#pragma once
#include "..\..\Includes\Components\ColliderComponent.h"
#include "..\..\Includes\Object\Player.h"
#include "..\..\Includes\Object\Ground.h"

ColliderComponent* ColliderComponent::collider = nullptr;

ColliderComponent::~ColliderComponent()
{
	delete collider;
}

bool ColliderComponent::OnCollision(Player& player,Ground& ground)
{

	if (Cast<RenderComponent>(ground.componentList.at("Render"))->spriteComp.getGlobalBounds().intersects(Cast<RenderComponent>(player.componentList.at("Render"))->spriteComp.getGlobalBounds())) {
		return true;
	}
	//for (Entity entity : entities) {
	//	if (entity.sprite.getGlobalBounds().intersects(this))
	//	{
	//		collide = true;
	//	}
	//	else {
	//		collide = false;
	//	}
	//}
	return false;
}
