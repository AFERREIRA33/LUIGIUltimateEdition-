#pragma once
// Engine

#include "..\..\Includes\Engine\GameEngine.h"

// Managers
#include "..\..\Includes\Manager\InputManager.h"
#include "..\..\Includes\Manager\PhysicManager.h"
#include "..\..\Includes\Manager\RenderManager.h"
#include "..\..\Includes\Manager\ObjectManager.h"
#include "..\..\Includes\Manager\EntityManager.h"
#include "..\..\Includes\Manager\CameraManager.h"

// Components
#include "..\..\Includes\Utils\Template.h"
#include "..\..\Includes\Components\TransformComponent.h"
#include "..\..\Includes\Components\ColliderComponent.h"
#include "..\..\Includes\Components\RenderComponent.h"
#include "..\..\Includes\Components\LifeComponent.h"

// Objects
#include "..\..\Includes\Object\Player.h"
#include "..\..\Includes\Object\Ground.h"
#include "..\..\Includes\Object\Wall.h"
#include "..\..\Includes\Object\BackGround.h"

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
	screenSize = FVector2D(1000, 540);
	if (!m_window)
		m_window = new sf::RenderWindow(sf::VideoMode(screenSize.x, screenSize.y), "LUIGI Ultimate Edition", sf::Style::Titlebar | sf::Style::Close);
	sf::View currentView = m_window->getView();
	currentView.reset(sf::FloatRect(0, 0, m_window->getSize().x, m_window->getSize().y));
	m_window->setView(currentView);
	m_window->setFramerateLimit(60);
	Start();
	CreateObject();
	while (m_window->isOpen())
	{
		deltaTime = deltaClock.restart().asSeconds();
		player->Update();
		m_window->clear();
		HandleInput(player, deltaTime);
		m_cameraManager->SetScreenPosition();
		m_physicsManager->Update(player, deltaTime);
		m_renderManager->DrawEntity();
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
	m_cameraManager = CameraManager::GetInstance();
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

void GameEngine::CreateObject() {
	BackGround* backGround = m_entityManager->CreateEntity<BackGround>("BackGround");
	backGround->Start(0, 0);

	player = m_entityManager->CreateEntity<Player>("Player");
	player->Start(500, 400);
	
	Ground* ground = m_entityManager->CreateEntity<Ground>("Ground");
	ground->Start(0, 500);
	
	/*Wall* wall = m_entityManager->CreateEntity<Wall>("Wall");
	wall->Start(800, 300);*/

	m_cameraManager->player = player;
}
void GameEngine::SetRegistry()
{
	// Components
	REGISTER_CLASS(TransformComponent);
	REGISTER_CLASS(RenderComponent);
	REGISTER_CLASS(ColliderComponent);
	REGISTER_CLASS(LifeComponent);
	

	// Entities
	REGISTER_CLASS(Player);
	REGISTER_CLASS(Ground);
	REGISTER_CLASS(Wall);
	REGISTER_CLASS(BackGround);
}
