#include "Game.h"

void Game::initializeWindow()
{
    sf::VideoMode videoMode = sf::VideoMode(1920, 1080);
    this->window = new sf::RenderWindow(videoMode, "Falling Down", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);
}

//CONSTRUCTORS and DESTRUCTORS
Game::Game()
{
    initializeWindow();
}

Game::~Game()
{
    delete this->window;
}

//MAIN FUNCTION for ENTRY POINT
void Game::run()
{
    while (this->window->isOpen())
    {
        updatePollEvents();

        update();

        render();
    }
}


//General Functions

void Game::updatePollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

//Main Update Function for order
void Game::update()
{
}


//Main Render function for order
void Game::render()
{
    this->window->clear();

    this->window->display();
}
