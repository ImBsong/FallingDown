#include "Blocks.h"

void Blocks::initVariables()
{
    this->blockWidth = 40.f;
    this->blockSize = sf::Vector2f(40.f, 10.f);
}

void Blocks::initRect()
{
    float topLeftPosition = 0.f;

    for (size_t i = 0; i < rectArray.size(); i++)
    {
        rectArray[i] = new sf::RectangleShape();
        rectArray[i]->setPosition(topLeftPosition, 1080.f);
        rectArray[i]->setSize(blockSize);
        rectArray[i]->setFillColor(sf::Color::White);
        topLeftPosition += blockWidth;
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

const size_t Blocks::getArraySize() const
{
    return rectArray.size();
}


void Blocks::move()
{
    for (size_t i = 0; i < rectArray.size(); i++)
    {
        rectArray[i]->move(0.f, -1.f);
    }
}

void Blocks::update()
{
    move();
}

void Blocks::render(sf::RenderTarget& target)
{
    for (size_t i = 0; i < rectArray.size(); i++)
    {
        target.draw(*rectArray[i]);
    }
}
