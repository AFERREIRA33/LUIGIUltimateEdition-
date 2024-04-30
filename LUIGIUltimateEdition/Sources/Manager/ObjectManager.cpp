#pragma once
#include "..\..\Includes\Manager\ObjectManager.h"

ObjectManager* ObjectManager::m_object = nullptr;


ObjectManager* ObjectManager::GetInstance() {
	if (m_object == nullptr) {
		m_object = new ObjectManager();
	}
	return m_object;
}

ObjectManager::ObjectManager() {

}


ObjectManager::~ObjectManager() {
	Registry.clear();
}