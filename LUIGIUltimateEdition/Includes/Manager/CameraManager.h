#pragma once
#include "..\Components\BaseObject.h"
class CameraManager : public BaseObject
{
public:
	virtual ~CameraManager();
	static CameraManager* GetInstance();
	DECLARE_RTTI(CameraManager, BaseObject);
private:
	CameraManager() = default;
	static CameraManager* m_instance;
};

