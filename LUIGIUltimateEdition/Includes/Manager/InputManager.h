#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "..\Components\BaseObject.h"
#include "..\..\Includes\Object\Player.h"
#include "..\Utils\Vector2D.h"

class InputManager : public BaseObject
{
public:
	virtual ~InputManager();
	void HandleInput(Player& player, float deltaTime);
	static InputManager* GetInstance();
	DECLARE_RTTI(InputManager, BaseObject);
private:
	InputManager();
	static InputManager* m_instance;
	sf::RenderWindow* m_window;
};

