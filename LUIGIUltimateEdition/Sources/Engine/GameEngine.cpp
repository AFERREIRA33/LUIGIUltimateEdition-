#pragma once
#include "..\..\Includes\Engine\GameEngine.h"
#include "..\..\Includes\Manager\InputManager.h"
#include "..\..\Includes\Manager\PhysicManager.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include <filesystem>

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
}

void GameEngine::RunGame()
{
	std::cout << GetClass().ClassID << std::endl;
	std::cout << GetClass().Parent->ClassID << std::endl;
	sf::Texture playerTexture;
	float changeX = 0;
	if (!playerTexture.loadFromFile("../../LUIGIUltimateEdition/Ressources/mario_projet.png"))
	{
	}
	sf::Sprite playerSprite(playerTexture);
	playerSprite.setPosition(500, 500);
	if (!m_window)
		m_window = new sf::RenderWindow(sf::VideoMode(960, 540), "LUIGI Ultimate Edition", sf::Style::Titlebar | sf::Style::Close);
	sf::View currentView = m_window->getView();
	currentView.reset(sf::FloatRect(0, 0, m_window->getSize().x, m_window->getSize().y));
	m_window->setView(currentView);
	m_window->setFramerateLimit(60);
	Start();
	PhysicManager PM;

	while (m_window->isOpen())
	{
		deltaTime = deltaClock.restart();
		m_window->clear();
		HandleInput(changeX);

		// float changeY = PM.Update(deltaTime.asSeconds());

		playerSprite.move(changeX, 0);
		changeX = 0;
		m_window->draw(playerSprite);
		m_window->display();
	}
}

void GameEngine::Start()
{
	m_inputManager = InputManager::GetInstance();
}

void GameEngine::HandleInput(float &changeX)
{
	m_inputManager->HandleInput(changeX);
}

sf::RenderWindow *GameEngine::GetWindow()
{
	return m_window;
}
