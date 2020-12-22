#include "Game.h"

void Game::initVariables()
{
    this->gameTime = 0.f;
    this->blockTimerMax = 50.f;
    this->blockTimer = blockTimerMax;
}

void Game::initWindow()
{
    sf::VideoMode videoMode = sf::VideoMode(1920, 1080);
    this->window = new sf::RenderWindow(videoMode, "Falling Down", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
    this->player = new Player();
    this->player->setPosition(this->window->getSize().x/2 - this->player->getBounds().width / 2, 0.f);
}

void Game::initBlocks()
{
    this->blocks = new Blocks();
}

//CONSTRUCTORS and DESTRUCTORS
Game::Game()
{
    initWindow();
    initPlayer();
    initBlocks();
}

Game::~Game()
{
    delete this->window;
    delete this->player;
    delete this->blocks;
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

void Game::updateInput()
{
    //Move commands
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player->move(-1.f, 0.f);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player->move(1.f, 0.f);
}

void Game::updateSideCollision()
{
    if (this->player->getBounds().left < 0)
        this->player->setPosition(0.f, this->player->getPosition().y);
    if (this->player->getBounds().left + this->player->getBounds().width > this->window->getSize().x)
        this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getPosition().y);
}

void Game::spawnBlocks()
{
    if (blockTimer >= blockTimerMax)
    {
        blockTimer = 0.f;
        //spawnblocks depending on timer (difficulty)
    }
    else
        ++blockTimer;
}

void Game::updateRandomBlocks()
{
    /*
    TODO:
        1. Choose how many blocks will appear x / 48
            0-1000: 24 blocks
            1000-2000: 20 blocks
            ...
            6000-7000 4 blocks
        2. Choose where they will be arranged in a line.  Diff array?
        3. Create them
        4. Create collision?
    */

    // Below is code to create collision
    for (size_t i = 0; i < blocks->getVecSize(); i++)
    {
        if (player->getBounds().top + player->getBounds().height >= blocks->getBounds(i).top)
            player->setPosition(player->getBounds().left, player->getBounds().top - 1.f);
    }
}


//Main Update Function for order
void Game::update()
{
    ++gameTime;
    this->player->update(); // just drops player
    this->blocks->update();
    updateInput(); // left and right
    updateSideCollision(); // checks wall collision
    updateRandomBlocks();
}


//Main Render function for order
void Game::render()
{
    this->window->clear();

    this->player->render(*window);

    this->blocks->render(*window);

    this->window->display();
}
