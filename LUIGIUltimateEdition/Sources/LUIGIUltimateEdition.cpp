
#include <iostream>
#include "..\Includes\Engine\GameEngine.h"
int main()
{
    GameEngine* game = GameEngine::GetInstance();
    game->RunGame();
}