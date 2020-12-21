#include "Player.h"


//Private Initializers
void Player::initVariables()
{
    this->speed = 5.f;
}

void Player::initTexture()
{
    if (!this->texture.loadFromFile("Textures/Ball.png"))
        std::cout << "Error: Ball Texture did not Load!\n";
}

void Player::initSprite()
{
    this->sprite.setTexture(texture);
    this->sprite.setScale(.05f, .05f);
}

//Constructor and Destructor
Player::Player()
{
    initVariables();
    initTexture();
    initSprite();
}

Player::~Player()
{
}

//Accessors
const sf::Vector2f & Player::getPosition() const
{
    return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

//Modifiers
void Player::setPosition(const float x, const float y)
{
    sprite.setPosition(x, y);
}

void Player::move(const float dirX, const float dirY)
{
    this->sprite.move(this->speed * dirX, this->speed * dirY);
}

//Functions
void Player::update()
{
    this->sprite.move(0.f, 1.f);
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}