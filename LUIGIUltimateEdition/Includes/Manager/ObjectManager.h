#pragma once
#include <vector>
#include <iostream>

#include "Factory.h"
#include "..\Components\BaseObject.h"

class ObjectManager : BaseObject
{
public:
	virtual ~ObjectManager();
	static ObjectManager* GetInstance();
	template<class T= BaseObject>
	void RegisterObject(std::string className) {
		factory.RegisterCreator(className, new DerivedBase<BaseObject, T>());
	}

	template<class T = BaseObject>
	T* CreateObject(std::string className) {
		BaseObject* object = factory.ConstructObject(className);
		Registry.push_back(object);
		return (T*)(object);
	}
	template<class T = BaseObject>
	T* RegisterCreateObject(std::string className) {
		factory.RegisterCreator(className, new DerivedBase<BaseObject, T>());
		BaseObject* object = factory.ConstructObject(className);
		Registry.push_back(object);
		return (T*)(object);
	}
	DECLARE_RTTI(ObjectManager, BaseObject);
private:
	Factory<BaseObject> factory;
	ObjectManager();
	static ObjectManager* m_object;
	std::vector<BaseObject*> Registry;
};

