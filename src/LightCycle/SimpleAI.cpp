#include "SimpleAI.h"
#include "iostream"

SimpleAI::SimpleAI(float x, float y, sf::Color c, short dir) : Player(x, y, c, dir) {
    std::cout << "New" << std::endl;
}

bool SimpleAI::checkTileCollision(const sf::Vector2f& tilePos, short dir, int offset) {
    switch (dir) {
        case 0:
            // check next upper "tile"
            if (_pos.x >= tilePos.x &&
                _pos.x <= tilePos.x + _size &&
                _pos.y >= tilePos.y - _size * offset &&
                _pos.y <= tilePos.y - _size * offset ) {
                return true;
            }
            break;

        case 1:
            // check next right "tile"
            if (_pos.x >= tilePos.x + _size * offset &&
                _pos.x <= tilePos.x + _size + _size * offset &&
                _pos.y >= tilePos.y &&
                _pos.y <= tilePos.y + _size) {
                return true;
            }
            break;

        case 2:
            // check next lower "tile"
            if (_pos.x >= tilePos.x &&
                _pos.x <= tilePos.x + _size &&
                _pos.y + _size * 2 >= tilePos.y &&
                _pos.y + _size * 2 <= tilePos.y + _size) {

                return true;
            }
            break;

        case 3:
            // check next right "tile"
            if (_pos.x - _size * 2 >= tilePos.x &&
                _pos.x - _size * 2 <= tilePos.x + _size &&
                _pos.y >= tilePos.y &&
                _pos.y <= tilePos.y + _size) {

                return true;
            }
            break;

        default:
            return false;
    }

    return false;
}

void SimpleAI::Update(const std::vector<Player*>& _players) {
    Player::Update(_players);

//    int change = rand() % 5;
//    setDir((change == 0) ? short(rand() % 4) : _dir);
    bool moveSelected = false;
    for (int i = 0; i < _players.size(); i++) {
        std::vector<sf::Vector2f>& tail = _players[i]->getTail();

        for (int j = 0; j < tail.size(); j++) {
            sf::Vector2f& curPos = tail[j];

            switch (_dir) {
                case 0:
                    // check next upper "tile"
                    if (checkTileCollision(curPos, 0)) {
                        // Check right "tile"
                        if (checkTileCollision(curPos, 1)) {
                            setDir(3); // Go Left
                            moveSelected = true;
                        } else {
                            setDir(1); // Got Right
                            moveSelected = true;
                        }
                    }
                    break;

                case 1:
                    // check next right "tile"
                    if (checkTileCollision(curPos, 1)) {
                        // check upper  "tile"
                        if (checkTileCollision(curPos, 0, 4)) {
                            setDir(2); // Go down
                            moveSelected = true;
                        } else {
                            setDir(0); // Got up
                            moveSelected = true;
                        }
                    }
                    break;

                case 2:
                    // check next lower "tile"
                    if (checkTileCollision(curPos, 2)) {
                        // Check right "tile"
                        if (checkTileCollision(curPos, 1)) {
                            setDir(3); // Go Left
                            moveSelected = true;
                        } else {
                            setDir(1); // Got Right
                            moveSelected = true;
                        }
                    }
                    break;
//
                case 3:
                    // check next right "tile"
                    if (checkTileCollision(curPos, 3)) {
                        // check upper  "tile"
                        if (checkTileCollision(curPos, 0)) {
                            setDir(2); // Go down
                            moveSelected = true;
                        } else {
                            setDir(0); // Got up
                            moveSelected = true;
                        }
                    }
                    break;

                default:
                    break;
            }

            // End tail loop
            if (moveSelected) break;
        }
        // End player loop
        if (moveSelected) break;
    }
}