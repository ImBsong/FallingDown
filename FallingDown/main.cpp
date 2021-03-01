#include "Game.h"

/*
    Game to capture childhood nostalgia.  Played this game on my TI-83 calculator.

    Goal is to get highest possible score, without touching the ceiling.

    Music thanks to https://patrickdearteaga.com/royalty-free-music/

*/

int main()
{
    std::srand(static_cast<unsigned int>(time(0)));

    Game game;
    game.run();

    return 0;
} 