#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

    float speed;

    //Private Initializers
    void initVariables();
    void initTexture();
    void initSprite();
public:
    //Constructor and Destructor
    Player();
    virtual ~Player();

    //Accessors
    const sf::Vector2f& getPosition() const;
    const sf::FloatRect getBounds() const;

    //Modifiers
    void setPosition(const float x, const float y);

    //Functions
    void move(const float dirX, const float dirY); 
    void update();
    void render(sf::RenderTarget& target);
};


#endif // !PLAYER_H



