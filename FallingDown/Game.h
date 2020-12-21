#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Blocks.h"

class Game
{
private:
    sf::RenderWindow * window;

    float gameTime;
    float blockTimer;
    float blockTimerMax;

    sf::Event ev;

    Player * player;

    Blocks * blocks;
    
    //Initializer functions
    void initVariables();
    void initWindow();
    void initPlayer();
    void initBlocks();
     
public:
    //Constructor and Destructor
    Game();
    virtual ~Game();

    //main function for entry point
    void run();

    //Accessors

    //Modifiers

    //General Functions
    void updatePollEvents();
    void updateInput();
    void updateSideCollision();
    void spawnBlocks();
    void updateRandomBlocks();

    ////Main Update function for order
    void update();

    //Main Render function for order
    void render();

};

#endif // !GAME_H