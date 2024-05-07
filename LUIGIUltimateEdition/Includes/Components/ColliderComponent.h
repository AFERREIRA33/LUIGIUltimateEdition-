#pragma once
#include <SFML/Graphics.hpp>
#include "..\Components\Component.h"


class Player;
class Ground;
class Entity;


class ColliderComponent : public Component
{
public:
	virtual ~ColliderComponent();
	bool OnCollision();
	Entity* obj;
	
	DECLARE_RTTI(ColliderComponent, Component);
private:
	bool collide;
	static ColliderComponent* collider;
};

