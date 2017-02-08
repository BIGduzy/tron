#include <SFML/Graphics.hpp>
#include "iostream"
#include "States/PlayState.h"

#ifndef TRON_GAME_H
#define TRON_GAME_H


class Game {
public:
    static const short WIDTH = 600;
    static const short HEIGHT = 480;
    Game();
    void Run();
private:
    const std::string GAME_NAME = "TRON";
    const float FPS = 60.0f;

    // TODO: State manager
    PlayState _curState;
};


#endif //TRON_GAME_H
