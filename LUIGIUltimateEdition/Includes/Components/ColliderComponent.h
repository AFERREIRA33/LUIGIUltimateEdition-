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
	bool OnCollision(Player* player, Ground* ground);
	DECLARE_RTTI(ColliderComponent, Component);
private:
	bool collide;
	static ColliderComponent* collider;
};

