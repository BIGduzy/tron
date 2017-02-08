#include "PlayState.h"
#include "../Game.h"

PlayState::PlayState() {
    // Create players
    for (short i = 0; i < _numPlayers; i++) {
        _players.push_back(
                Player(
                        i * (Game::WIDTH - PLAYER_SIZE * 2), // x position
                        Game::HEIGHT / 2, // y position
                        (i % 2 == 0) ? sf::Color::Blue : sf::Color::Green, // color
                        (i % 2 == 0) ? short(1) : short(3) // Direction
                )
        );
    }

    if(!_bgTexture.loadFromFile("src/Resources/background.jpg")) {
        std::cout << "Error loading background image" << std::endl;
    }
    _background.setTexture(_bgTexture);
}

void PlayState::Update(sf::RenderWindow& window) {
    if (gameOver) return;

    // TODO: Do this for every user
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) _players[0].setDir(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _players[0].setDir(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _players[0].setDir(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _players[0].setDir(3);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) _players[1].setDir(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) _players[1].setDir(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) _players[1].setDir(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) _players[1].setDir(3);

    for (short i = 0; i < _numPlayers; i++) {
        _players[i].Update();

        for (short j = 0; j < _numPlayers; j++) {
//             TODO: Also check collision on self
            if (_players[i].CollidesWith(_players[j])) {
                gameOver = true;
            }
        }
    }
}

void PlayState::Render(sf::RenderWindow& window) {
    // Draw background
    window.draw(_background);


    for (short i = 0; i < _numPlayers; i++) {
        _players[i].Render(window);
    }

}