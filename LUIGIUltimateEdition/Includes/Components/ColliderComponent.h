#pragma once
#include "..\Components\Component.h"
#include <SFML/Graphics.hpp>

class ColliderComponent : public Component
{
public:
	ColliderComponent() = default;

	virtual ~ColliderComponent();
	bool OnCollision();
	DECLARE_RTTI(ColliderComponent, Component);
private:
	bool collide;
};

