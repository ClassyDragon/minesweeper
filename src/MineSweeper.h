#pragma once
#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include "TextureManager/TextureManager.h"
#include "Menu.h"
#include "Game.h"

class MineSweeper {
    public:
        // Default Constructor:
        MineSweeper();

        // Init Functions:
        void initTextures();

        // Game Loop:
        void startGame();

        // Updates:
        void update();
        void updateEvent();

        // Render:
        void render();
    private:
        // Program window and event:
        sf::RenderWindow window;
        sf::Event event;

        // Current State:
        std::stack<State*> currentState;
};
