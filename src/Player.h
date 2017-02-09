#include <SFML/Graphics.hpp>
#include "vector"

#ifndef TRON_PLAYER_H
#define TRON_PLAYER_H


class Player {
public:
    Player(float x, float y, sf::Color c, short dir);
    void setDir(const short d);
    bool CollidesWith(Player& player);
    bool isOutOfBounds(int width, int height) const;
    void Update();
    void Render(sf::RenderWindow& window);
private:
    const short _size = 3;
    short _dir;
    int _speed = 6;
    sf::Color _color;
    std::vector<sf::Vector2f> _tail;
    sf::Vector2f _pos;
};


#endif //TRON2_6_PLAYER_H
