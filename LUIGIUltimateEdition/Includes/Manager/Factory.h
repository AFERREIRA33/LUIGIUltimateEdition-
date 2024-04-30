#pragma once
#include <unordered_map>
#include <string>
class BaseObject;

template <class BaseClass = BaseObject>
class Creator {
public:
	virtual ~Creator();
	virtual BaseClass* Create() = 0;
};

template <class BaseClass = BaseObject, class DerivedClass = BaseObject>
class DerivedBase : public Creator<BaseClass> {
public:
	virtual BaseClass* Create() override {
		BaseClass* object = new DerivedClass();
		return object;
	}
};

template <class BaseClass = BaseObject>
class Factory
{
public:
	Factory() = default;
	~Factory() {
		Clear();
	};

	bool isRegistered(std::string className) {
		return FactoryConstructors.contains(className);
	}
	void RegisterCreator(std::string classToCreate, Creator<BaseClass*> classCreator) {
		if (!isRegistered(classToCreate)) {
			FactoryConstructors.insert(std::make_pair(classToCreate, classCreator));
		}
	}
	BaseClass* ConstructObject(std::string objectClass) {
		BaseClass* newObject = nullptr;
		if (isRegistered(objectClass)) {
			newObject = FactoryConstructors.at(objectClass)->Create();
		}
		return newObject;
	}
	void Clear() {
		FactoryConstructors.clear();
	}

	std::unordered_map<std::string, Creator<BaseClass>*> FactoryConstructors;

};

