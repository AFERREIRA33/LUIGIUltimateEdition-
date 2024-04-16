#pragma once

#include "SFML/Graphics.hpp"


class GameEngine
{
public:
	static GameEngine* GetInstance();
	virtual ~GameEngine();
	void RunGame();
private:
	GameEngine() = default;
	static GameEngine* m_engine;
	sf::RenderWindow* m_window;
};