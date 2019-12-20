#pragma once
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

    private:
        // Sprite:
        Sprite::sprite s;
};
