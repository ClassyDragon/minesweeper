#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sprite/Sprite.h"

class Tile {
    public:
        // Default Constructor:
        Tile();

        // Draw to window:
        void drawto(sf::RenderWindow* window);

        // Set position:
        void setPosition(sf::Vector2f pos);

        // On Left Click:
        void onClick(sf::Vector2i mousePos);

    private:
        // Sprite:
        Sprite::sprite s;

        // Type: (Mine or no mine)
        int type;

        // State: (Revealed or not revealed)
        int state;
};
