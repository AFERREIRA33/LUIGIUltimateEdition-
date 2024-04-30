#pragma once
#include "..\..\Includes\Components\RenderComponent.h"

RenderComponent* RenderComponent::render = nullptr;

//RenderComponent::RenderComponent(sf::Texture& texture)
//{
//	this->textureComp = texture;
//	this->spriteComp = LoadSprite();
//}

RenderComponent::~RenderComponent()
{
	delete render;
}

sf::Sprite RenderComponent::LoadSprite()
{
	spriteComp.setTexture(textureComp);
	return spriteComp;
}

void RenderComponent::SetSpritePos(FVector2D objTransform)
{
	transform = objTransform;
}



