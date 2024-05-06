#pragma once
#include "..\..\Includes\Manager\EntityManager.h"

EntityManager* EntityManager::m_instance = nullptr;

EntityManager* EntityManager::GetInstance() {
	if (m_instance == nullptr) {
		m_instance = new EntityManager();
	}
	return m_instance;
}

EntityManager::~EntityManager() {
	entityList.clear();
}
EntityManager::EntityManager() {

}