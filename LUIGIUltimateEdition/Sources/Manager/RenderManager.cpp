     #pragma once
#include "..\..\Includes\Manager\RenderManager.h"
#include "..\..\Includes\Manager\EntityManager.h"
#include "..\..\Includes\Engine\GameEngine.h"


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
void RenderManager::DrawEntity() 
{
	for (Entity* e : EntityManager::GetInstance()->GetEntityList())
	{
		if (e->isRender) {
			GameEngine::GetInstance()->m_window->draw(Cast<RenderComponent>(e->componentList.at("Render"))->spriteComp);
		}
	}
}