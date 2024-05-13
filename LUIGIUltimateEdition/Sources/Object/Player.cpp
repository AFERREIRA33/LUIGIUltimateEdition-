#pragma once
#include <iostream>
#include "..\..\Includes\Object\Player.h"

Player::~Player()
{
}

void Player::Start(float x, float y)
{
	transformInitial.x = x;
	transformInitial.y = y;
	Tag = "Player";
	TransformComponent* c_transform = ObjectManager::GetInstance()->CreateObject<TransformComponent>(TransformComponent::StaticClass().ClassID);
	RenderComponent* c_render = ObjectManager::GetInstance()->CreateObject<RenderComponent>(RenderComponent::StaticClass().ClassID);
	ColliderComponent* c_collider = ObjectManager::GetInstance()->CreateObject<ColliderComponent>(ColliderComponent::StaticClass().ClassID);
	componentList.insert(std::make_pair("Transform", c_transform));
	componentList.insert(std::make_pair("Render",c_render));
	componentList.insert(std::make_pair("Collider", c_collider));
	Cast<TransformComponent>(componentList.at("Transform"))->UpdatePosition(transformInitial);
	if (!texture.loadFromFile("../../LUIGIUltimateEdition/Ressources/mario_projet.png"))
	{
	}
	Cast<RenderComponent>(componentList.at("Render"))->LoadSprite(texture, Cast<TransformComponent>(componentList.at("Transform"))->position);
	Cast<ColliderComponent>(componentList.at("Collider"))->obj = this;
	size = Cast<RenderComponent>(componentList.at("Render"))->spriteComp.getGlobalBounds().getSize().x;
}

void Player::Update() {
	//std::cout << Cast<TransformComponent>(componentList.at("Transform"))->position.ToString() << std::endl;
	//std::cout << Cast<RenderComponent>(componentList.at("Render"))->spriteComp.getGlobalBounds().getSize().x << std::endl;
}
void Player::PlayerMove(float speed,float deltaTime)
{
	ChangePosition(FVector2D(speed * deltaTime, 0));
}

void Player::PlayerJump(FVector2D velocity,float deltaTime)
{
	if (!isJumping)
	{
		ChangePosition(velocity);
		isJumping = true;
	}
}
void Player::ChangePosition(FVector2D pos) {

	pos.y = Cast<TransformComponent>(componentList.at("Transform"))->position.y + pos.y;
	pos.x = Cast<TransformComponent>(componentList.at("Transform"))->position.x + pos.x;
	Cast<TransformComponent>(componentList.at("Transform"))->position = pos;
	//Cast<RenderComponent>(componentList.at("Render"))->spriteComp.setPosition(sf::Vector2f(pos.x, pos.y));
	
}
void Player::Collide()
{
}
