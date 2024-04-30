#pragma once
#include "..\..\Includes\Components\TransformComponent.h"

TransformComponent* TransformComponent::transform = nullptr;


//TransformComponent::TransformComponent(FVector2D pos, FVector2D rot, FVector2D scal)
//{
//	position = pos;
//	rotation = rot;
//	scale = scal;
//}

TransformComponent::~TransformComponent()
{
	delete transform;
}

void TransformComponent::UpdatePosition(FVector2D pos)
{
	position = pos;
}

void TransformComponent::UpdateRotation(FVector2D rot)
{
	rotation = rot;
}
