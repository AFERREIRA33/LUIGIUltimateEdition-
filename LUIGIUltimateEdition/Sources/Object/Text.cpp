#include "..\..\Includes\Object\Text.h"
#include "..\..\Includes\Engine\GameEngine.h"

Text::~Text()
{
}

void Text::Start(float x, float y)
{
	transformInitial.x = x;
	transformInitial.y = y;
	TransformComponent* c_transform = ObjectManager::GetInstance()->CreateObject<TransformComponent>(TransformComponent::StaticClass().ClassID);
	RenderComponent* c_render = ObjectManager::GetInstance()->CreateObject<RenderComponent>(RenderComponent::StaticClass().ClassID);
	componentList.insert(std::make_pair("Transform", c_transform));
	componentList.insert(std::make_pair("Render", c_render));
	Cast<TransformComponent>(componentList.at("Transform"))->UpdatePosition(transformInitial);
	Tag = "Text";

}
