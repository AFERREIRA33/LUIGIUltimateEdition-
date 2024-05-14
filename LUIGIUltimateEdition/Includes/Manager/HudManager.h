#pragma once
#include <SFML/Graphics.hpp>
#include "..\Components\BaseObject.h"



class HudManager : public BaseObject
{
public:
	static HudManager* GetInstance();
	virtual ~HudManager();
	void UpdateHud();
	void DrawText();
	DECLARE_RTTI(HudManager, BaseObject);
private:

	sf::Font font;
	sf::Text lifeText;
	HudManager();
	static HudManager* m_hudManager;
};

