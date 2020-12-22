#ifndef BLOCKS_H
#define BLOCKS_H

#include <vector>

#include <SFML/Graphics.hpp>

class Blocks
{
private:
    std::vector<sf::RectangleShape *> rectVec;
    float blockWidth;
    sf::Vector2f blockSize;

    //Initializers
    void initVariables();
    void initRect();
public:
    //Constructor and Destructor
    Blocks();
    virtual ~Blocks();

    //Accessor
    const sf::FloatRect getBounds(const size_t number) const;
    const size_t getVecSize() const;

    //Functions
    void move();

    void update();
    void render(sf::RenderTarget& target);
};

#endif // !BLOCKS_H
