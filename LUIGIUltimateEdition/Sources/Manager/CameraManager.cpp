#include "..\..\Includes\Manager\CameraManager.h"
CameraManager* CameraManager::m_instance = nullptr;

CameraManager* CameraManager::GetInstance() {
	if (m_instance == nullptr) {
		m_instance = new CameraManager();
	}
	return m_instance;
}
CameraManager::~CameraManager() {

}