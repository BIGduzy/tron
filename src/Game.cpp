#include "Game.h"

Game::Game() : _curState() {
    srand(time(0));
}

void Game::Run() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), GAME_NAME);
    window.setVerticalSyncEnabled(false);

    // sfml event
    sf::Event event;

    // Game loop variables
    sf::Clock clock;
    double t = 1.0 / FPS;
    double dt = 0.0;
    double curTime = 0;
    // for fps counter
    sf::Clock fpsClock;
    double timer = 0;
    int updates = 0;
    int frames = 0;

    // Game loop
    while (window.isOpen())	{
        // Events
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) window.close(); // Close one close button
        }

        // Fps / gameloop timers
        timer = fpsClock.getElapsedTime().asSeconds();
        curTime = clock.getElapsedTime().asSeconds();
        dt += curTime / t;

        /**************/
        /****UPDATE****/
        /**************/
        while (dt >= 1) {
            // Update Here
            _curState.Update(window);


            sf::Time elapsed = clock.restart();
            updates++;
            dt--;
        }

        frames++;
        clock.restart(); // reset game loop clock

        if (timer > 1) { // once every sec
            window.setTitle(GAME_NAME + " |  fps: " + std::to_string(frames) + " | Ups: " + std::to_string(updates)); // set fps in window
            fpsClock.restart(); // reset fpsClock
            updates = 0;
            frames = 0;
        }



        /**************/
        /****RENDER****/
        /**************/
        window.clear();
        // Draw here
        _curState.Render(window);

        window.display();
    }
}