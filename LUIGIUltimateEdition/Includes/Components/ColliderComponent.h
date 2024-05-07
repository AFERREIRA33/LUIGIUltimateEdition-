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
	std::vector<std::string> OnCollision();
	Entity* obj;
	std::vector<std::string> collisionActive;
	DECLARE_RTTI(ColliderComponent, Component);
private:
	bool collide;
	static ColliderComponent* collider;
};

