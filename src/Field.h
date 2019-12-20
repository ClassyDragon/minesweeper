#pragma once
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

    private:
        Tile tiles[nWidth][nHeight];
};
