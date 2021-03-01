#ifndef GAME_H
#define GAME_H

#include <vector>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "Blocks.h"

class Game
{
private:
    bool gameOver;
    sf::RenderWindow * window;

    float gameTime;
    float blockTimer;
    float blockTimerMax;

    float boostCooldown;
    float boostCooldownMax;

    sf::Event ev;

    Player * player;

    std::vector<Blocks *> blocks;

    //GUI
    sf::Font font;
    sf::Text pointText;
    sf::Text gameOverText;

    //Audio
    sf::SoundBuffer sfxBoostBuffer;
    sf::Sound sfxBoost;
    sf::Time sfxOffSet;

    sf::Music music; // You don't need to load this
    
    //Initializer functions
    void initVariables();
    void initWindow();
    void initText();
    void initSound();
    void initPlayer();
     
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
    void updateGui();
    void updateInput();
    void updateCollision();
    void spawnBlocks();
    void removeBlocks();
    void checkDeath();
    int getBallPosition();
    void resetGame();

    ////Main Update function for order
    void update();

    //Main Render function for order
    void render();

    void renderGui();
};

#endif // !GAME_H