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
	virtual void Start();
	virtual ~Entity();
	int ID;
	std::string Tag;
	sf::Texture texture;
	std::unordered_map<std::string, Component*> componentList;
	FVector2D transformInitial;
	DECLARE_RTTI(Entity, BaseObject);
};

