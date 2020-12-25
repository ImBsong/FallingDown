#include "Game.h"

void Game::initVariables()
{
    this->gameTime = 0.f;
    this->blockTimerMax = 90.f;
    this->blockTimer = blockTimerMax;
    this->gameOver = false;
}

void Game::initWindow()
{
    sf::VideoMode videoMode = sf::VideoMode(1920, 1080);
    this->window = new sf::RenderWindow(videoMode, "Falling Down", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initText()
{
    if (!this->font.loadFromFile("Fonts/alpha_echo.ttf"))
        std::cout << "ERROR: Font did not load!\n";

    this->pointText.setFont(this->font);
    this->pointText.setCharacterSize(20);
    this->pointText.setFillColor(sf::Color::White);
    this->pointText.setPosition(25.f, 40.f);

    this->gameOverText.setFont(this->font);
    this->gameOverText.setCharacterSize(100);
    this->gameOverText.setFillColor(sf::Color::Red);
    this->gameOverText.setPosition(25.f, 40.f);
    this->gameOverText.setString("Game Over!");
    this->gameOverText.setPosition(
        (window->getSize().x / 2.f) - gameOverText.getGlobalBounds().width / 2.f,
        window->getSize().y / 2.f - gameOverText.getGlobalBounds().height / 2.f);
}

void Game::initPlayer()
{
    this->player = new Player();
    this->player->setPosition(this->window->getSize().x/2 - this->player->getBounds().width / 2, 20.f);
}

//CONSTRUCTORS and DESTRUCTORS
Game::Game()
{
    initVariables();
    initWindow();
    initText();
    initPlayer();
}

Game::~Game()
{
    delete this->window;
    delete this->player;

    for (auto *i : this->blocks)
    {
        delete i;
    }
}

//MAIN FUNCTION for ENTRY POINT
void Game::run()
{
    while (this->window->isOpen())
    {
        updatePollEvents();

        if (!gameOver)
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

void Game::updateGui()
{
    std::stringstream ss;
    ss << "Points: " << this->gameTime;

    this->pointText.setString(ss.str());
}

void Game::updateInput()
{
    //Move commands
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player->move(-1.f, 0.f);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player->move(1.f, 0.f);
}

void Game::updateCollision()
{
    //First check player collision
    if (this->player->getBounds().left < 0)
        this->player->setPosition(1.f, this->player->getPosition().y);
    if (this->player->getBounds().left + this->player->getBounds().width > this->window->getSize().x)
        this->player->setPosition(this->window->getSize().x - this->player->getBounds().width - 1.f, this->player->getPosition().y);

    //Check Collision with blocks
    for (auto *blockline : blocks)
    {
        if (player->getBounds().top + player->getBounds().height >= blockline->getBounds(0).top && player->getBounds().top + player->getBounds().height <= blockline->getBounds(0).top + blockline->getBounds(0).height)
        {
            // Move player if they are on top of a visible block
            for (size_t i = 0; i < blockline->blockSelectArray.size(); i++)
            {
                if (blockline->blockSelectArray[getBallPosition()].visible)
                {
                    player->move(0.f, -.6f);
                }
                break;
            }
        }
    }
}

void Game::spawnBlocks()
{
    if (blockTimer >= blockTimerMax)
    {
        blockTimer = 0.f;
        blocks.emplace_back(new Blocks());
        blocks.back()->randomizeBlocks(this->gameTime);
    }
    else
        ++blockTimer;
}

void Game::removeBlocks()
{  
    unsigned counter = 0;
    for (auto *i : blocks)
    {
        if (i->getLifeTime() > 1100.f)
        {
            delete blocks.at(counter);
            blocks.erase(blocks.begin() + counter);
            --counter;
        }
        ++counter;
    }
}

void Game::checkDeath()
{
    if (player->getBounds().top < 0.f)
        gameOver = true;
}

int Game::getBallPosition()
{
    return static_cast<int>(this->player->getPosition().x / 40);
}

void Game::renderGui()
{
    this->window->draw(pointText);
}

//Main Update Function for order
void Game::update()
{
    ++gameTime;

    updateGui();

    checkDeath();

    spawnBlocks();

    this->player->update(); // just drops player

    for (auto *i : blocks)
        i->update();

    updateInput(); // left and right

    updateCollision(); // checks wall collision 

    removeBlocks();
}

//Main Render function for order
void Game::render()
{
    this->window->clear();

    renderGui();

    for (auto *i : blocks)
        i->render(*window);

    this->player->render(*window);

    if (gameOver)
        window->draw(gameOverText);

    this->window->display();
}
