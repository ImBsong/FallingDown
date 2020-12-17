#ifndef GAME_H
#define GAME_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{
private:
    sf::RenderWindow * window;

    sf::Event ev;
    
    //Initializer functions
    void initializeWindow();
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

    ////Main Update function for order
    void update();

    //Main Render function for order
    void render();

};

#endif // !GAME_H