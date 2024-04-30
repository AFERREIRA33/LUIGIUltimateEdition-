#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include "..\Components\BaseObject.h"


class Entity : public BaseObject
{
public:
	Entity();
	virtual void Start();
	virtual ~Entity();
	int ID;
	std::unordered_map<std::string, int> mymap;
	DECLARE_RTTI(Entity, BaseObject);
};

