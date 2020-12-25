#ifndef BLOCKS_H
#define BLOCKS_H

#include <array>

#include <SFML/Graphics.hpp>

class Blocks
{
private:

    float blockWidth;
    sf::Vector2f blockSize;
    float lifeTime;

    //Initializers
    void initVariables();
    void initRect();
public:
    struct block {
        bool visible;
        float topLeftPosition;
    };

    std::array<sf::RectangleShape *, 48> rectArray;
    std::array<block, 48> blockSelectArray;

    //Constructor and Destructor
    Blocks();
    virtual ~Blocks();

    //Accessor
    const sf::FloatRect getBounds(const size_t number) const;
    const size_t getVecSize() const;
    const float getLifeTime() const;
    const int getBlockWidth() const;

    //Functions
    void move();
    void hideBlocks(int centerBlock, int numOfNeighbors);
    void randomizeBlocks(float gameTime);

    void update();
    void render(sf::RenderTarget& target);
};

#endif // !BLOCKS_H