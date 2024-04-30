#pragma once
#include "..\..\Includes\Engine\GameEngine.h"
#include "..\..\Includes\Manager\InputManager.h"
#include "..\..\Includes\Manager\PhysicManager.h"
#include "..\..\Includes\Manager\RenderManager.h"
#include "..\..\Includes\Manager\ObjectManager.h"

GameEngine *GameEngine::m_engine = nullptr;
GameEngine *GameEngine::GetInstance()
{
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
	delete m_inputManager;
	delete m_renderManager;
	delete m_physicsManager;
}

void GameEngine::RunGame()
{
	
	float changeX = 0;

	
	if (!m_window)
		m_window = new sf::RenderWindow(sf::VideoMode(960, 540), "LUIGI Ultimate Edition", sf::Style::Titlebar | sf::Style::Close);
	sf::View currentView = m_window->getView();
	currentView.reset(sf::FloatRect(0, 0, m_window->getSize().x, m_window->getSize().y));
	m_window->setView(currentView);
	m_window->setFramerateLimit(60);
	Start();

	while (m_window->isOpen())
	{
		deltaTime = deltaClock.restart();
		m_window->clear();
		HandleInput(changeX);
		//float changeY = m_physics->Update(deltaTime.asSeconds());
		/*playerSprite.move(changeX, 0);*/
		changeX = 0;
		/*m_window->draw(playerSprite);*/
		m_window->display();
	}
}


void GameEngine::Start()
{
	m_inputManager = InputManager::GetInstance();
	m_physicsManager = PhysicManager::GetInstance();
	m_renderManager = RenderManager::GetInstance();
	m_objectManager = ObjectManager::GetInstance();
}

void GameEngine::HandleInput(float &changeX)
{
	m_inputManager->HandleInput(changeX);
}

sf::RenderWindow *GameEngine::GetWindow()
{
	return m_window;
}
