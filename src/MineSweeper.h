#pragma once
#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include "TextureManager/TextureManager.h"
#include "Menu.h"
#include "Game.h"
#include "global.h"

class MineSweeper {
    public:
        // Default Constructor:
        MineSweeper();

        // Init Functions:
        void initTextures();
        void initKeys();

        // Game Loop:
        void startGame();

        // Updates:
        void update();
        void updateEvent();
        void updateInput();

        // Render:
        void render();
    private:
        // Program window and event:
        sf::RenderWindow window;
        sf::Event event;

        // Current State:
        std::stack<State*> currentState;

        // Key States:
        int keyState[numKeys];
};
