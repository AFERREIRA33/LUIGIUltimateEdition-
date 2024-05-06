#pragma once

#include <iostream>
#include <vector>

#include "..\Components\BaseObject.h"
#include "..\Manager\ObjectManager.h"
#include "..\Object\Entity.h"

class EntityManager : public BaseObject
{
public:
	virtual ~EntityManager();
	static EntityManager* GetInstance();
	DECLARE_RTTI(EntityManager, BaseObject);
	template<class T = Entity>
	T* CreateEntity(std::string className) {
		Entity* entity = ObjectManager::GetInstance()->CreateObject<T>(className);
		entityList.push_back(entity);
		return (T*)(entity);
	}
	std::vector<Entity*> GetEntityList() {
		return entityList;
	}
private:
	EntityManager();
	static EntityManager* m_instance;
	std::vector<Entity*> entityList;
};

