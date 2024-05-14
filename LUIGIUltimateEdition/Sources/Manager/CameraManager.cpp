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
	FVector2D newPosOnScreen;
	float posOnScreenRightCorner;
	FVector2D objTransform;
	FVector2D playerPos = Cast<TransformComponent>(player->componentList.at("Transform"))->position;
	float camCenter = 500;
	if (playerPos.x >=  minPosition && playerPos.x <= maxPosition) {
		for (Entity* e : EntityManager::GetInstance()->GetEntityList())
		{
			if (e->Tag != "Player") {
				objTransform = Cast<TransformComponent>(e->componentList.at("Transform"))->position;
				newPosOnScreen.x = objTransform.x - ((playerPos.x - camCenter)/(e->Tag == "BackGround" ? 3 : 1));
				posOnScreenRightCorner = newPosOnScreen.x + e->size;
				Cast<RenderComponent>(e->componentList.at("Render"))->spriteComp.setPosition(newPosOnScreen.x, objTransform.y);
				
				if ((newPosOnScreen.x <= 0 && posOnScreenRightCorner  >= 1000) || (newPosOnScreen.x >= 0 && newPosOnScreen.x <= 1000) || (posOnScreenRightCorner >= 0 && posOnScreenRightCorner <= 1000)) {
					e->isRender = true;
				}
				else {
					e->isRender = false;
				}
			}
			else {
				Cast<RenderComponent>(player->componentList.at("Render"))->spriteComp.setPosition(playerRendX, playerPos.y);
			}
		}
	}
	else {
		if (playerPos.x >= minPosition) {
			Cast<RenderComponent>(player->componentList.at("Render"))->spriteComp.setPosition(playerPos.x - levelSize, playerPos.y);
		}
		else {
			Cast<RenderComponent>(player->componentList.at("Render"))->spriteComp.setPosition(playerPos.x, playerPos.y);
		}
	}
}

CameraManager::CameraManager() {
	minPosition = 500;
	maxPosition = 1500;
	levelSize = maxPosition - minPosition;
}