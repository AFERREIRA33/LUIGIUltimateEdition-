#include "..\..\Includes\Manager\InputManager.h"
#include "..\..\Includes\Engine\GameEngine.h"


InputManager* InputManager::m_instance = nullptr;

InputManager* InputManager::GetInstance() {
	if (m_instance == nullptr) {
		m_instance = new InputManager();
	}
	return m_instance;
}

InputManager::~InputManager() {

}
void InputManager::HandleInput() {
	using event = sf::Event;
	event e;
	while (m_window->pollEvent(e))
	{
		switch (e.type)
		{
		case event::Closed:
			m_window->close();
			break;
		}
	}
}

InputManager::InputManager()
{
	m_window = GameEngine::GetInstance()->GetWindow();
}