#pragma once
#include "..\Object\Entity.h"
#include <SFML/Graphics.hpp>

class Text : public Entity
{
public:
	Text() = default;
	virtual ~Text();
	void Start(float x, float y) override;
	sf::Text text;
	sf::Font font;
	DECLARE_RTTI(Text, Entity);
};

