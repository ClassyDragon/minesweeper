#include "Game.h"

// Default Constructor:
Game::Game() {
}

// Constructor:
Game::Game(sf::RenderWindow* window) : window(window) {
    this->bg = Sprite::background("res/background.png");
}

// Update:
void Game::update() {
}

// Render:
void Game::render() {
    this->bg.drawto(window);
}

// Get State:
int Game::getState() {
    return 1;
}
