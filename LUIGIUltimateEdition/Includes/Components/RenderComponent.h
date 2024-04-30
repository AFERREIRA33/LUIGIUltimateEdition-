#pragma once
#include <SFML/Graphics.hpp>
#include "..\Components\Component.h"
#include "..\Utils\Vector2D.h"


class RenderComponent : public Component
{
public:
	/*RenderComponent(sf::Texture& texture);*/
	virtual ~RenderComponent();
	sf::Sprite LoadSprite();
	void SetSpritePos(FVector2D objTransform);
	DECLARE_RTTI(RenderComponent, Component);

private:
	static RenderComponent* render;
	sf::Texture textureComp;
	sf::Sprite spriteComp;
	FVector2D transform;

};



