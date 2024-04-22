#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"

class InputManager
{
public:
	virtual ~InputManager();
	void HandleInput();
	static InputManager* GetInstance();
private:
	InputManager();
	static InputManager* m_instance;
	sf::RenderWindow* m_window;
};

