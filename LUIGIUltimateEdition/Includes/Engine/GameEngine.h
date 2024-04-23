#pragma once

#include "..\..\Includes\Manager\InputManager.h"
#include "..\..\Includes\Components\BaseObject.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include <filesystem>
class InputManager;

class GameEngine : public BaseObject
{
public:

	static GameEngine* GetInstance();
	virtual ~GameEngine();
	void RunGame();
	sf::RenderWindow* GetWindow();
	sf::Clock deltaClock;
	sf::Time deltaTime;
private:
	GameEngine() = default;
	static GameEngine* m_engine;
	sf::RenderWindow* m_window;
	InputManager* m_inputManager;
	void Start();
	void HandleInput(float& changeX);
	DECLARE_RTTI(GameEngine, BaseObject);
};