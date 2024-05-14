#pragma once
#include "..\Object\Entity.h"

class BackGround : public Entity
{
public:
	BackGround() = default;
	virtual ~BackGround();
	void Start(float x, float y) override;

	DECLARE_RTTI(BackGround, Entity);
};

