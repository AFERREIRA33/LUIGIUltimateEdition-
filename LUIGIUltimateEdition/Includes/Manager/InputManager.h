#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"
#include "..\Components\BaseObject.h"

class InputManager : public BaseObject
{
public:
	virtual ~InputManager();
	void HandleInput(float& changeX);
	static InputManager* GetInstance();
	DECLARE_RTTI(InputManager, BaseObject);
private:
	InputManager();
	static InputManager* m_instance;
	sf::RenderWindow* m_window;
};

