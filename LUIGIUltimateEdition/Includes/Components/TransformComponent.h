#pragma once
#include "..\Components\Component.h"
#include "..\Utils\Vector2D.h"

class TransformComponent : public Component
{
public:
	TransformComponent();
	/*TransformComponent(FVector2D pos, FVector2D rot, FVector2D scal);*/
	virtual ~TransformComponent();
	//static TransformComponent* transform;
	void UpdatePosition(FVector2D pos);
	void UpdateRotation(FVector2D rot);
	DECLARE_RTTI(TransformComponent, Component);

	FVector2D position;
	FVector2D rotation;
	FVector2D scale;
};