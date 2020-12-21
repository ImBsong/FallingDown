#include "Game.h"

int main()
{
    std::srand(static_cast<unsigned int>(time(0)));

    Game game;
    game.run();

    return 0;
} 