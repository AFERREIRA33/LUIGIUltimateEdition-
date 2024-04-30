#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>

#include "..\Components\BaseObject.h"


class InputManager;
class PhysicManager;
class ObjectManager;
class RenderManager;

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
	PhysicManager* m_physicsManager;
	InputManager* m_inputManager;
	RenderManager* m_renderManager;
	ObjectManager* m_objectManager;
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
	void SetRegistry();
};

#define REGISTER_CLASS(Class)\
    ObjectManager::GetInstance()->RegisterObject<Class>(Class::StaticClass().ClassID);
