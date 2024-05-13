#include "..\..\Includes\Object\Wall.h"


void Wall::Start()
{
	transformInitial.x = 800;
	transformInitial.y = 300;
	Tag = "Ground";
	TransformComponent* c_transform = ObjectManager::GetInstance()->CreateObject<TransformComponent>(TransformComponent::StaticClass().ClassID);
	RenderComponent* c_render = ObjectManager::GetInstance()->CreateObject<RenderComponent>(RenderComponent::StaticClass().ClassID);
	componentList.insert(std::make_pair("Transform", c_transform));
	componentList.insert(std::make_pair("Render", c_render));
	Cast<TransformComponent>(componentList.at("Transform"))->UpdatePosition(transformInitial);
	if (!texture.loadFromFile("../../LUIGIUltimateEdition/Ressources/Wall.png"))
	{
	}
	Cast<RenderComponent>(componentList.at("Render"))->LoadSprite(texture, Cast<TransformComponent>(componentList.at("Transform"))->position);
}
