#include "Player.h"

#ifndef TRON_SIMPLEAI_H
#define TRON_SIMPLEAI_H


class SimpleAI : public Player {
public:
    SimpleAI(float x, float y, sf::Color c, short dir);
    virtual void Update(const std::vector<Player*>& _players);
private:
    bool checkTileCollision(const sf::Vector2f& tilePos, short dir, int offset = 1);
};


#endif //TRON_SIMPLEAI_H
