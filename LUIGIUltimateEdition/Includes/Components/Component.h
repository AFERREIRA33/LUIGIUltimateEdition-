#pragma once

#include "SFML/Graphics.hpp"
#include "..\Components\BaseObject.h"

class Component : public BaseObject
{
public:
	Component();
	virtual ~Component();
	int ID;
	DECLARE_RTTI(Component, BaseObject);
private:

};

