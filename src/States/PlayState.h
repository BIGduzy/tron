#include "vector"

#include "State.h"
#include "../Player.h"

#ifndef TRON_PLAYSTATE_H
#define TRON_PLAYSTATE_H


class PlayState : public State {
public:
    PlayState();
    virtual void Update(sf::RenderWindow& window);
    virtual void Render(sf::RenderWindow& window);

private:
    // TODO: Replace with game over state
    bool gameOver = false;
    const short PLAYER_SIZE = 3;
    short _numPlayers = 2;
    std::vector<Player> _players;

    sf::Texture _bgTexture;
    sf::Sprite _background;

};


#endif //TRON_PLAYSTATE_H
