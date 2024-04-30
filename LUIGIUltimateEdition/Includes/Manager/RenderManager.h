#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "..\Components\BaseObject.h"


class RenderManager : public BaseObject
{
public:
	static RenderManager* GetInstance();
	virtual ~RenderManager();
	DECLARE_RTTI(RenderManager, BaseObject);

private:
	RenderManager();
	void DrawEntity();
	sf::Texture playerTexture;
	static RenderManager* m_renderManager;
};

