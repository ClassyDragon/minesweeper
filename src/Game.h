#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Sprite/Sprite.h"
#include "Field.h"
#include "Button.h"

class Game;

class ResetButton : public Button {
    public:
        // Default constructor:
        ResetButton();
        ResetButton(Game* game);
        ~ResetButton();

        // Virtual Overrides:
        void onClick();
        void onHover();
    private:
        Game* game;
};

class Game : public State {
    public:
        // Default Constructor:
        Game();

        // Constructor:
        Game(sf::RenderWindow* window);

        // Init Functions:
        void initResetButton();

        // Update:
        void update();

        // Render:
        void render();

        // Get State:
        int getState();

        // Input:
        void leftClick();
        void rightClick();

        // Reinitialize field:
        void reset();
    private:
        // Window pointer:
        sf::RenderWindow* window;

        // Background:
        Sprite::background bg;

        // Field:
        Field field;

        // Reset Button:
        ResetButton resetButton;
};
