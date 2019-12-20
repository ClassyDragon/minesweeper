#include "Tile.h"

// Default Constructor:
Tile::Tile() {
    this->s = Sprite::sprite("res/tile.png");
}

// Draw to window:
void Tile::drawto(sf::RenderWindow* window) {
    s.drawto(window);
}

// Set Position:
void Tile::setPosition(sf::Vector2f pos) {
    this->s.setPosition(pos);
}
