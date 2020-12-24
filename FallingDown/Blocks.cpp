#include "Blocks.h"

void Blocks::initVariables()
{
    this->blockWidth = 40.f;
    this->blockSize = sf::Vector2f(40.f, 10.f);
    this->lifeTime = 0.f;

    float positionSetter = 0.f;

    for (size_t i = 0; i < blockSelectArray.size(); i++)
    {
        blockSelectArray[i].visible = true;
        blockSelectArray[i].topLeftPosition = positionSetter;
        positionSetter += blockWidth;
    }
}

void Blocks::initRect()
{
    for (size_t i = 0; i < rectArray.size(); i++)
    {
        rectArray[i] = new sf::RectangleShape();
        rectArray[i]->setPosition(blockSelectArray[i].topLeftPosition, 1080.f);
        rectArray[i]->setSize(blockSize);
        rectArray[i]->setFillColor(sf::Color::White);
    }
}

Blocks::Blocks()
{
    initVariables();
    initRect();
}

Blocks::~Blocks()
{
    for (size_t i = 0; i < rectArray.size(); i++)
    {
        delete rectArray[i];
    }
}

const sf::FloatRect Blocks::getBounds(const size_t number) const
{
    return rectArray[number]->getGlobalBounds();
}

const size_t Blocks::getVecSize() const
{
    return rectArray.size();
}

const float Blocks::getLifeTime() const
{
    return this->lifeTime;
}


void Blocks::move()
{
    for (size_t i = 0; i < rectArray.size(); i++)
    {
        rectArray[i]->move(0.f, -1.f);
    }
}

void Blocks::hideBlocks(int centerBlock, int numOfNeighbors)
{
    //I should make this recursive.  V2 thing
    switch (numOfNeighbors)
    {
    case 0:
        rectArray[centerBlock]->setFillColor(sf::Color(0, 0, 0, 255));
        break;
    case 1:
        rectArray[centerBlock - 1]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 1]->setFillColor(sf::Color(0, 0, 0, 255));
        break;
    case 2:
        rectArray[centerBlock - 2]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock - 1]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 1]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 2]->setFillColor(sf::Color(0, 0, 0, 255));
        break;
    case 3:
        rectArray[centerBlock - 3]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock - 2]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock - 1]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 1]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 2]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 3]->setFillColor(sf::Color(0, 0, 0, 255));
        break;
    case 4:
        rectArray[centerBlock - 4]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock - 3]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock - 2]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock - 1]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 1]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 2]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 3]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 4]->setFillColor(sf::Color(0, 0, 0, 255));
        break;
    default:
        rectArray[centerBlock - 4]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock - 3]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock - 2]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock - 1]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 1]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 2]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 3]->setFillColor(sf::Color(0, 0, 0, 255));
        rectArray[centerBlock + 4]->setFillColor(sf::Color(0, 0, 0, 255));
        break;
    }
}

void Blocks::randomizeBlocks(float gameTime)
{
    int randCenterBlock = rand() % 42 + 5;
    
    // Make logic based on game time.  Adjacent blocks will disappear based on difficulty

    if (gameTime < 1000)
    {
        //Level 1
        hideBlocks(randCenterBlock, 4);
    }
    else if (gameTime >= 1000 && gameTime < 2000)
    {
        //Level 2
        hideBlocks(randCenterBlock, 3);
    }
    else if (gameTime >= 2000 && gameTime < 3000)
    {
        //Level 3
        hideBlocks(randCenterBlock, 2);
    }
    else
    {
        //Level 4
        hideBlocks(randCenterBlock, 1);
    }
}

void Blocks::update()
{
    move();
    ++lifeTime;
}

void Blocks::render(sf::RenderTarget& target)
{
    for (size_t i = 0; i < rectArray.size(); i++)
    {
        target.draw(*rectArray[i]);
    }
}