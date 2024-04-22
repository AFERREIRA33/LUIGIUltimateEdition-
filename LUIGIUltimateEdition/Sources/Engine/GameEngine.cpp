#include "..\..\Includes\Engine\GameEngine.h"
#include "..\..\Includes\Manager\InputManager.h"
#include "iostream"
#include <SFML/Graphics.hpp>

GameEngine* GameEngine::m_engine = nullptr;

GameEngine* GameEngine::GetInstance() {
	std::cout << "isNull" << std::endl;
	if (m_engine == nullptr)
	{
		std::cout << "Null" << std::endl;
		m_engine = new GameEngine();
	}
	return m_engine;
}

GameEngine::~GameEngine()
{
	delete m_engine;
	delete m_window;
	delete m_inputManager;
}

void GameEngine::RunGame() {
	if (!m_window)
		m_window = new sf::RenderWindow(sf::VideoMode(960, 540), "LUIGI Ultimate Edition", sf::Style::Titlebar | sf::Style::Close);
	sf::View currentView = m_window->getView();
	currentView.reset(sf::FloatRect(0, 0, m_window->getSize().x, m_window->getSize().y));
	m_window->setView(currentView);
	Start();
	while (m_window->isOpen()) {
		HandleInput();
	}
}

void GameEngine::Start() {
	m_inputManager = InputManager::GetInstance();
}

void GameEngine::HandleInput() {
	m_inputManager->HandleInput();
}
sf::RenderWindow* GameEngine::GetWindow() {
	if (m_window->isOpen()) {
		std::cout << "open" << std::endl;
	}
	else {
		std::cout << "close" << std::endl;
	}
	return m_window;
}