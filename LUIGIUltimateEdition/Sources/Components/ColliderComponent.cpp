#pragma once

#include "..\..\Includes\Components\ColliderComponent.h"

ColliderComponent::~ColliderComponent()
{
}

bool ColliderComponent::OnCollision()
{
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
