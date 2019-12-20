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
    this->field.drawto(window);
}

// Get State:
int Game::getState() {
    return 1;
}

// Input:
void Game::leftClick() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    field.leftClick(mousePos);
}

void Game::rightClick() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    field.rightClick(mousePos);
}
