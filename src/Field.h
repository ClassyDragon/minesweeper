#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <time.h>
#include "Tile.h"
#include "global.h"

class Field {
    public:
        // Default Constructor:
        Field();

        // Update:
        void update();

        // Draw:
        void drawto(sf::RenderWindow* window);

        // Poll a left click:
        void leftClick(sf::Vector2i mousePos);
        void rightClick(sf::Vector2i mousePos);

        // Reveal surrounding tiles:
        void revealSurroundingTiles(int x, int y);

        // Check if indecies are out of bounds:
        bool isOutOfBounds(sf::Vector2i indicies);
        bool isOutOfBounds(int x, int y);

    private:
        Tile tiles[nWidth][nHeight];
        std::vector<Tile*> mines;
};
