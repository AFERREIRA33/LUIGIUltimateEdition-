#include "..\..\Includes\Manager\HudManager.h"
#include "..\..\Includes\Object\Player.h"
#include "..\..\Includes\Engine\GameEngine.h"



HudManager* HudManager::m_hudManager = nullptr;

HudManager* HudManager::GetInstance() {
	if (m_hudManager == nullptr)
	{
		m_hudManager = new HudManager();
	}
	return m_hudManager;
}

HudManager::HudManager() {

}

HudManager::~HudManager()
{
	delete m_hudManager;
}

void HudManager::UpdateHud()
{
	lifeText.setString(std::to_string(Cast<LifeComponent>(GameEngine::GetInstance()->GetPlayer()->componentList.at("Life"))->life));
}



void HudManager::DrawText()
{
	if (!font.loadFromFile("../../LUIGIUltimateEdition/Ressources/arial.ttf"))
	{
	}
	lifeText.setFont(font);
	GameEngine::GetInstance()->m_window->draw(lifeText);
}
