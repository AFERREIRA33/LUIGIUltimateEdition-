#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include "..\Components\BaseObject.h"
#include "..\Components\Component.h"
#include "..\Components\ColliderComponent.h"
#include "..\Components\RenderComponent.h"
#include "..\Components\TransformComponent.h"
#include "..\..\Includes\Manager\ObjectManager.h"
#include "..\Utils\Template.h"




class Entity : public BaseObject
{
public:
	Entity();
	virtual ~Entity();
	virtual void Start(float x, float y) = 0;
	int ID;
	bool isRender;
	std::string Tag;
	sf::Texture texture;
	std::unordered_map<std::string, Component*> componentList;
	FVector2D transformInitial;
	int size;
	DECLARE_RTTI(Entity, BaseObject);
};

