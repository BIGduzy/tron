#include <SFML/Graphics.hpp>
#include "vector"

#ifndef TRON_PLAYER_H
#define TRON_PLAYER_H


class Player {
public:
    sf::Color _color;
    Player(int x, int y, sf::Color c, short dir);
    void setDir(const short d);
    bool CollidesWith(Player& player);
    void Update();
    void Render(sf::RenderWindow& window);
private:
    const short _size = 3;
    short _dir;
    int _speed = 4;
    std::vector<sf::Vector2f> _tail;
    sf::Vector2f _pos;
};


#endif //TRON2_6_PLAYER_H
