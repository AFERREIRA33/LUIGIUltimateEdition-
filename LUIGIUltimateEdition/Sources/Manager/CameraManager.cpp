#pragma once
#include "..\..\Includes\Manager\CameraManager.h"
#include "..\..\Includes\Object\Player.h"
#include "..\..\Includes\Manager\EntityManager.h"
#include "..\..\Includes\Object\Entity.h"


CameraManager* CameraManager::m_instance = nullptr;

CameraManager* CameraManager::GetInstance() {
	if (m_instance == nullptr) {
		m_instance = new CameraManager();
	}
	return m_instance;
}
CameraManager::~CameraManager() {

}

void CameraManager::SetScreenPosition() {
	float playerRendX = Cast<RenderComponent>(player->componentList.at("Render"))->spriteComp.getPosition().x;
	FVector2D newPosScreen;
	FVector2D objTransform;
	FVector2D playerPos = Cast<TransformComponent>(player->componentList.at("Transform"))->position;
	float camCenter = 500;
	if (playerPos.x >=  camCenter) {
		for (Entity* e : EntityManager::GetInstance()->GetEntityList())
		{
			if (e->Tag != "Player") {
				objTransform = Cast<TransformComponent>(e->componentList.at("Transform"))->position;
				newPosScreen.x = objTransform.x - (playerPos.x - camCenter);
				Cast<RenderComponent>(e->componentList.at("Render"))->spriteComp.setPosition(newPosScreen.x, objTransform.y);
			}
			else {
				Cast<RenderComponent>(player->componentList.at("Render"))->spriteComp.setPosition(playerRendX, playerPos.y);
			}
		}
	}
	else {
		Cast<RenderComponent>(player->componentList.at("Render"))->spriteComp.setPosition(playerPos.x, playerPos.y);
	}
}