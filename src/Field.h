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

    private:
        Tile tiles[nWidth][nHeight];
};
