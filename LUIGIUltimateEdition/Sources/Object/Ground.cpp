#include "..\..\Includes\Object\Ground.h"

void Ground::Start(float x, float y)
{
	transformInitial.x = x;
	transformInitial.y = y;
	Tag = "Ground";
	TransformComponent* c_transform = ObjectManager::GetInstance()->CreateObject<TransformComponent>(TransformComponent::StaticClass().ClassID);
	RenderComponent* c_render = ObjectManager::GetInstance()->CreateObject<RenderComponent>(RenderComponent::StaticClass().ClassID);
	componentList.insert(std::make_pair("Transform", c_transform));
	componentList.insert(std::make_pair("Render", c_render));
	Cast<TransformComponent>(componentList.at("Transform"))->UpdatePosition(transformInitial);
	if (!texture.loadFromFile("../../LUIGIUltimateEdition/Ressources/ground.png"))
	{
	}
	Cast<RenderComponent>(componentList.at("Render"))->LoadSprite(texture, Cast<TransformComponent>(componentList.at("Transform"))->position);
	size = Cast<RenderComponent>(componentList.at("Render"))->spriteComp.getGlobalBounds().getSize().x;
}
