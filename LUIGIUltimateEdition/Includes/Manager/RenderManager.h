#pragma once
#include "SFML/Graphics.hpp"
#include "..\Components\BaseObject.h"
#include "iostream"

class RenderManager : public BaseObject
{
public:
	static RenderManager* GetInstance();
	RenderManager();
	virtual ~RenderManager();
	DECLARE_RTTI(RenderManager, BaseObject);

private:
	void DrawEntity();
	sf::Texture playerTexture;
	static RenderManager* m_renderManager;
};

