#pragma once

#include "..\Manager\InputManager.h"
#include "..\Manager\PhysicManager.h"
#include "..\Components\BaseObject.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include <filesystem>

class InputManager;
class PhysicManager;

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
	PhysicManager* m_physics;
	InputManager* m_inputManager;
	void Start();
	void HandleInput(float& changeX);
	virtual FClass GetClass() override {
		FClass Parent = BaseObject::StaticClass();
		return FClass("GameEngine", { Parent });
	};
	static FClass StaticClass() {
		FClass Parent = BaseObject::StaticClass();
		return FClass("GameEngine", { Parent });
	};
};