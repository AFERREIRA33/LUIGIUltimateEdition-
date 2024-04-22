#pragma once

#include "SFML/Graphics.hpp"

class InputManager;

class GameEngine
{
public:
	static GameEngine* GetInstance();
	virtual ~GameEngine();
	void RunGame();
	sf::RenderWindow* GetWindow();
private:
	GameEngine() = default;
	static GameEngine* m_engine;
	sf::RenderWindow* m_window;
	InputManager* m_inputManager;
	void Start();
	void HandleInput();
};