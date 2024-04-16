#include "..\..\Includes\Engine\GameEngine.h"
#include "iostream"
#include <SFML/Graphics.hpp>

GameEngine* GameEngine::m_engine = nullptr;

GameEngine* GameEngine::GetInstance() {
	if (m_engine == nullptr)
	{
		m_engine = new GameEngine();
	}
	return m_engine;
}

GameEngine::~GameEngine()
{
	delete m_engine;
	delete m_window;
}

void GameEngine::RunGame() {
	if (!m_window)
		m_window = new sf::RenderWindow(sf::VideoMode(960, 540), "LUIGI Ultimate Edition", sf::Style::Titlebar | sf::Style::Close);
	while (m_window->isOpen()) {

	}
}
