#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sprite/Sprite.h"
#include "global.h"

class Tile {
    public:
        // Default Constructor:
        Tile();

        // Constructor:
        Tile(int tileType);

        // Draw to window:
        void drawto(sf::RenderWindow* window);

        // Set position:
        void setPosition(sf::Vector2f pos);

        // On Left Click:
        int onClick(sf::Vector2i mousePos);
        int onRightClick(sf::Vector2i mousePos);

        // Explode!
        void pow();

        // Increment number of adjacent mines:
        void incNumAdjacentMines();

        // Get number of adjacent mines:
        int getNumAdjacentMines();

        // Get Current State:
        int getState();

        // Reveal:
        void reveal();

        // Flagging:
        void flag();
        void unflag();

        // TESTING:
        void printNumAdjacentMines();

    private:
        // Sprite:
        Sprite::sprite s;

        // Type: (Mine or no mine)
        int type;

        // State: (Revealed or not revealed)
        int state;

        // Number of mines adjacent:
        int numAdjacentMines;
};
