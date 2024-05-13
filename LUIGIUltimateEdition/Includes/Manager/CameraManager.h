#pragma once
#include "..\Components\BaseObject.h"
class Player;

class CameraManager : public BaseObject
{
public:
	virtual ~CameraManager();
	static CameraManager* GetInstance();
	DECLARE_RTTI(CameraManager, BaseObject);
	void SetScreenPosition();
	float position;
	Player* player;
private:
	CameraManager();
	static CameraManager* m_instance;
	float minPosition;
	float maxPosition;
	float levelSize;
};

