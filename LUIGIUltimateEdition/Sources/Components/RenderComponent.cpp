#pragma once
#include "..\..\Includes\Components\RenderComponent.h"


RenderComponent* RenderComponent::render = nullptr;

RenderComponent::RenderComponent()
{

}

RenderComponent::~RenderComponent()
{
	delete render;
}



void RenderComponent::LoadSprite(sf::Texture& texture, FVector2D objTransform)
{
	textureComp = texture;
	spriteComp = sf::Sprite(textureComp);
	spriteComp.setPosition(objTransform.x, objTransform.y);
}

void RenderComponent::SetSpritePos(FVector2D objTransform)
{
	transform = objTransform;
}



