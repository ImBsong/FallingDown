#include "Blocks.h"

void Blocks::initVariables()
{
    this->blockWidth = 40.f;
    this->blockSize = sf::Vector2f(40.f, 10.f);
    this->rectVec.reserve(48);
}

void Blocks::initRect()
{
    float topLeftPosition = 0.f;
    int counter = 0;

    for (size_t i = 0; i < rectVec.capacity(); i++)
    {
        if (i > 10)
        {
            rectVec.emplace_back(new sf::RectangleShape());
            rectVec[counter]->setPosition(topLeftPosition, 1000.f);
            rectVec[counter]->setSize(blockSize);
            rectVec[counter]->setFillColor(sf::Color::White);
            topLeftPosition += blockWidth;
            ++counter;
        }
        else
        {
            topLeftPosition += blockWidth;
        }
    }
}

Blocks::Blocks()
{
    initVariables();
    initRect();
}

Blocks::~Blocks()
{
    for (size_t i = 0; i < rectVec.size(); i++)
    {
        delete rectVec[i];
    }
}

const sf::FloatRect Blocks::getBounds(const size_t number) const
{
    return rectVec[number]->getGlobalBounds();
}

const size_t Blocks::getVecSize() const
{
    return rectVec.size();
}


void Blocks::move()
{
    for (size_t i = 0; i < rectVec.size(); i++)
    {
        rectVec[i]->move(0.f, -1.f);
    }
}

void Blocks::update()
{
    move();
}

void Blocks::render(sf::RenderTarget& target)
{
    for (size_t i = 0; i < rectVec.size(); i++)
    {
        target.draw(*rectVec[i]);
    }
}
