#pragma once
#include <SFML/Graphics.hpp>
#include "..\Components\Component.h"


class ColliderComponent : public Component
{
public:
	virtual ~ColliderComponent();
	bool OnCollision();
	DECLARE_RTTI(ColliderComponent, Component);
private:
	bool collide;
	static ColliderComponent* collider;
};

