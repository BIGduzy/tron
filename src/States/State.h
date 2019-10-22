#include <SFML/Graphics.hpp>

#ifndef TRON_STATE_H
#define TRON_STATE_H


class State {
public:
    State();
    virtual void Update(sf::RenderWindow& window);
    virtual void Render(sf::RenderWindow& window);
    virtual void Init();
};


#endif //TRON_STATE_H
