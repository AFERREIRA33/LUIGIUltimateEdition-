     #pragma once
#include "..\..\Includes\Manager\RenderManager.h"

RenderManager* RenderManager::m_renderManager = nullptr;

RenderManager* RenderManager::GetInstance() {
	if (m_renderManager == nullptr)
	{
		m_renderManager = new RenderManager();
	}
	return m_renderManager;
}

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
	delete m_renderManager;
}

//RenderManager::DrawEntity() 
//{
//
//}


//sf::Sprite playerSprite(playerTexture);
//playerSprite.setPosition(500, 500);