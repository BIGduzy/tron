#include "Player.h"

Player::Player(int x, int y, sf::Color c, short dir) {
    _pos = {x, y};
    _color = c;
    _dir = dir;
}

void Player::setDir(const short d) {
    if (d == 0 && _dir != 2) _dir = 0;
    if (d == 1 && _dir != 3) _dir = 1;
    if (d == 2 && _dir != 0) _dir = 2;
    if (d == 3 && _dir != 1) _dir = 3;
}

bool Player::CollidesWith(Player& player) {
    // Check collision on head
    sf::CircleShape shape(3);
    shape.setFillColor(_color);
    shape.setPosition(_pos);

    bool collision = false;
    if (!collision) {
        for (int i = 0; i < player._tail.size(); i++) {
            collision = (abs(int(_pos.x - player._tail[i].x)) + abs(int(_pos.y - player._tail[i].y)) <= _size);
            if (collision) break; // No need to search further
        }
    }

    return collision;
}

void Player::Update() {
    // TODO: This should be done better
    _tail.push_back(_pos);

    // Prevent suicide
    if (_dir == 0) _pos.y -= _speed; // Up
    if (_dir == 1) _pos.x += _speed; // Right
    if (_dir == 2) _pos.y += _speed; // Down
    if (_dir == 3) _pos.x -= _speed; // Left
}

void Player::Render(sf::RenderWindow& window) {
    // Draw player
    sf::CircleShape shape(3);
    shape.setFillColor(_color);
    shape.setPosition(_pos);
    window.draw(shape);

    // Draw Tail
    for (int i = 0; i < _tail.size(); i++) {
        sf::CircleShape shape(_size);
        shape.setFillColor(_color);
        shape.setPosition(_tail[i]);
        window.draw(shape);
    }
}