#include "..\..\Includes\Manager\InputManager.h"
#include "..\..\Includes\Engine\GameEngine.h"
#include "..\..\Includes\Manager\PhysicManager.h"

InputManager* InputManager::m_instance = nullptr;

InputManager* InputManager::GetInstance() {
	if (m_instance == nullptr) {
		m_instance = new InputManager();
	}
	return m_instance;
}

InputManager::~InputManager() {

}
void InputManager::HandleInput(Player* player, float deltaTime) {
	using event = sf::Event;
	event e;

	
	while (m_window->pollEvent(e))
	{
		std::cout << e.Count << std::endl;
		switch (e.type)
		{
		case event::Closed:
			m_window->close();
			break;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && PhysicManager::GetInstance()->canMoveL)
		{
			PhysicManager::GetInstance()->direction = -1;
			player->PlayerMove(-200,deltaTime);
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && PhysicManager::GetInstance()->canMoveR)
		{
			PhysicManager::GetInstance()->direction = 1;
			player->PlayerMove(200, deltaTime);
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			PhysicManager::GetInstance()->direction = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !player->isJumping && PhysicManager::GetInstance()->canJump)
		{
			PhysicManager::GetInstance()->AddForce();
			player->PlayerJump(PhysicManager::GetInstance()->velocity, deltaTime);
		}
	}
}

InputManager::InputManager()
{
	m_window = GameEngine::GetInstance()->GetWindow();
}