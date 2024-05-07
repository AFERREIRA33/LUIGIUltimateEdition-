#pragma once
// Engine

#include "..\..\Includes\Engine\GameEngine.h"

// Managers
#include "..\..\Includes\Manager\InputManager.h"
#include "..\..\Includes\Manager\PhysicManager.h"
#include "..\..\Includes\Manager\RenderManager.h"
#include "..\..\Includes\Manager\ObjectManager.h"
#include "..\..\Includes\Manager\EntityManager.h"

// Components
#include "..\..\Includes\Utils\Template.h"
#include "..\..\Includes\Components\TransformComponent.h"
#include "..\..\Includes\Components\ColliderComponent.h"
#include "..\..\Includes\Components\RenderComponent.h"

// Objects
#include "..\..\Includes\Object\Player.h"
#include "..\..\Includes\Object\Ground.h"

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
		m_window = new sf::RenderWindow(sf::VideoMode(1000, 540), "LUIGI Ultimate Edition", sf::Style::Titlebar | sf::Style::Close);
	sf::View currentView = m_window->getView();
	currentView.reset(sf::FloatRect(0, 0, m_window->getSize().x, m_window->getSize().y));
	m_window->setView(currentView);
	m_window->setFramerateLimit(60);
	Start();
	Player* player = m_entityManager->CreateEntity<Player>("Player");
	Ground* ground = m_entityManager->CreateEntity<Ground>("Ground");
	player->Start();
	ground->Start();

	while (m_window->isOpen())
	{
		deltaTime = deltaClock.restart().asSeconds();

		m_window->clear();
		HandleInput(player, deltaTime);
		m_physicsManager->Update(player, ground, deltaTime);
		// float changeY = m_physics->Update(deltaTime.asSeconds());
		/*playerSprite.move(changeX, 0);*/
		// changeX = 0;
		player->Update();
		m_window->draw(Cast<RenderComponent>(player->componentList.at("Render"))->spriteComp);
		m_window->draw(Cast<RenderComponent>(ground->componentList.at("Render"))->spriteComp);
		m_window->display();
	}
}

void GameEngine::Start()
{
	m_inputManager = InputManager::GetInstance();
	m_physicsManager = PhysicManager::GetInstance();
	m_renderManager = RenderManager::GetInstance();
	m_objectManager = ObjectManager::GetInstance();
	m_entityManager = EntityManager::GetInstance();
	SetRegistry();
}

void GameEngine::HandleInput(Player* player, float deltaTime)
{
	m_inputManager->HandleInput(player, deltaTime);
}

sf::RenderWindow *GameEngine::GetWindow()
{
	return m_window;
}

void GameEngine::SetRegistry()
{
	// Components
	REGISTER_CLASS(TransformComponent);
	REGISTER_CLASS(RenderComponent);
	REGISTER_CLASS(ColliderComponent);

	// Entities
	REGISTER_CLASS(Player);
	REGISTER_CLASS(Ground);
}
