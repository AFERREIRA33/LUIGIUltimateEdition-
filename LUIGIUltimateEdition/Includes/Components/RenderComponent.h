#pragma once
#include <SFML/Graphics.hpp>
#include "..\Components\Component.h"
#include "..\Utils\Vector2D.h"


class RenderComponent : public Component
{
public:
	RenderComponent();
	virtual ~RenderComponent();
	void LoadSprite(sf::Texture& texture, FVector2D objTransform);
	void SetSpritePos(FVector2D objTransform);
	DECLARE_RTTI(RenderComponent, Component);
	sf::Sprite spriteComp;

private:
	static RenderComponent* render;
	sf::Texture textureComp;
	
	FVector2D transform;

};



