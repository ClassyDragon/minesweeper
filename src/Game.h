#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Sprite/Sprite.h"

class Game : public State {
    public:
        // Default Constructor:
        Game();

        // Constructor:
        Game(sf::RenderWindow* window);

        // Update:
        void update();

        // Render:
        void render();

        // Get State:
        int getState();
    private:
        // Window pointer:
        sf::RenderWindow* window;

        // Background:
        Sprite::background bg;
};
