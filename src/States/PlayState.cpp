#include "PlayState.h"
#include "../Game.h"

PlayState::PlayState() {
    if(!_bgTexture.loadFromFile("src/Resources/background.jpg")) {
        std::cout << "Error loading background image" << std::endl;
    }
    _background.setTexture(_bgTexture);

    Init();
}

void PlayState::Init() {
    gameOver = false;

    // Create players
    _players.clear(); // use clear so we can use the init function to reset level
    for (short i = 0; i < _numPlayers; i++) {
        _players.push_back(
                new Player(
                        i * (Game::WIDTH - PLAYER_SIZE * 2), // x position
                        Game::HEIGHT / 2, // y position
                        (i % 2 == 0) ? sf::Color::Blue : sf::Color::Green, // color
                        (i % 2 == 0) ? short(1) : short(3) // Direction
                )
        );
    }
    // Add AI
    _players.push_back(
            new SimpleAI(
                    (Game::WIDTH - PLAYER_SIZE * 2), // x position
                    Game::HEIGHT / 2, // y position
                    sf::Color::Green, // color
                    3 // Direction
            )
    );
}

void PlayState::Update(sf::RenderWindow& window) {
    if (gameOver) {
        // Reset level on R key
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            Init();
        }
        return;
    }

    // TODO: Do this for every user
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) _players[0]->setDir(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _players[0]->setDir(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _players[0]->setDir(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _players[0]->setDir(3);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) _players[1]->setDir(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) _players[1]->setDir(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) _players[1]->setDir(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) _players[1]->setDir(3);

    for (short i = 0; i < _players.size(); i++) {
        _players[i]->Update(_players);

        // Out of bounds check
        if (_players[i]->isOutOfBounds(Game::WIDTH, Game::HEIGHT)) {
            gameOver = true;
        }

        for (short j = 0; j < _players.size(); j++) {
            if (_players[i]->CollidesWith(*_players[j])) {
                gameOver = true;
            }
        }
    }
}

void PlayState::Render(sf::RenderWindow& window) {
    // Draw background
    window.draw(_background);


    for (short i = 0; i < _players.size(); i++) {
        _players[i]->Render(window);
    }

}