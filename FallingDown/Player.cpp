#include "Player.h"

//Private Initializers
void Player::initVariables()
{
    this->speedBoostTimer = 0;
    this->speedBoosted = 20.f;
    this->speedRegular = 7.f;
    this->speed = this->speedRegular;
}

void Player::initTexture()
{
    if (!this->texture.loadFromFile("Textures/Ball.png"))
        std::cout << "Error: Ball Texture did not Load!\n";
}

void Player::initSprite()
{
    this->sprite.setTexture(texture);
    this->sprite.setScale(.03f, .03f);
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

void Player::setPlayerSpeed(const float newSpeed)
{
    this->speed = newSpeed;
}

void Player::move(const float dirX, const float dirY)
{
    this->sprite.move(this->speed * dirX, this->speed * dirY);
}

void Player::startSpeedBoost()
{
    this->speedBoostTimer = 20;
    setPlayerSpeed(speedBoosted);
}

//Functions
void Player::update()
{
    if (this->speedBoostTimer > 0)
    {
        --speedBoostTimer;
    }
    else
        setPlayerSpeed(speedRegular);

    this->sprite.move(0.f, 2.f);    
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}