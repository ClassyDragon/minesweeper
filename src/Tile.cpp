#include "Tile.h"

// Default Constructor:
Tile::Tile() {
    this->type = TileType::VACANT;
    this->state = TileState::HIDDEN;
    this->numAdjacentMines = 0;
    this->s = Sprite::sprite("res/tile.png");
    this->s.setTextureRect(sf::IntRect(0, 0, 50, 50));
}

// Constructor:
Tile::Tile(int tileType) : type(tileType) {
    this->state = TileState::HIDDEN;
    if (tileType == TileType::MINE) {
        numAdjacentMines = -1;
    }
    this->s = Sprite::sprite("res/tile.png");
    this->s.setTextureRect(sf::IntRect(0, 0, 50, 50));
}

// Draw to window:
void Tile::drawto(sf::RenderWindow* window) {
    s.drawto(window);
}

// Set Position:
void Tile::setPosition(sf::Vector2f pos) {
    this->s.setPosition(pos);
}

// On Left mouse click:
int Tile::onClick(sf::Vector2i mousePos) {
    if (this->s.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        return this->type;
    }
    return -1;
}

int Tile::onRightClick(sf::Vector2i mousePos) {
    if (this->s.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        return this->state;
    }
    return -1;
}

// Explode!
void Tile::pow() {
    this->s.setTextureRect(sf::IntRect(50, 0, 50, 50));
}

// Increment number of adjacent mines:
void Tile::incNumAdjacentMines() {
    this->numAdjacentMines++;
}

// Get number of adjacent mines:
int Tile::getNumAdjacentMines() {
    return this->numAdjacentMines;
}

// Get current state:
int Tile::getState() {
    return this->state;
}

// Reveal:
void Tile::reveal() {
    if (this->type != TileType::MINE) {
        if (this->numAdjacentMines != 0) {
            this->s.setTextureRect(sf::IntRect(50 * numAdjacentMines + 50, 0, 50, 50));
        }
        else {
            this->s.setTextureRect(sf::IntRect(550, 0, 50, 50));
        }
        this->state = TileState::REVEALED;
    }
}

// Flagging:
void Tile::flag() {
    this->s.setTextureRect(sf::IntRect(500, 0, 50, 50));
    this->state = TileState::FLAGGED;
}

void Tile::unflag() {
    this->s.setTextureRect(sf::IntRect(0, 0, 50, 50));
    this->state = TileState::HIDDEN;
}

// TESTING:
void Tile::printNumAdjacentMines() {
    std::cout << this->numAdjacentMines << std::endl;
}
