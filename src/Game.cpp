#include "Game.h"

// Default Constructor:
Game::Game() {
}

// Constructor:
Game::Game(sf::RenderWindow* window) : window(window) {
    this->bg = Sprite::background("res/background.png");
    initResetButton();
}

// Init Functions:
void Game::initResetButton() {
    this->resetButton = ResetButton(this);
}

// Update:
void Game::update() {
    sf::Vector2i pos = sf::Mouse::getPosition(*window);
    bool clicked = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    this->resetButton.updateState(pos, clicked);
    if (this->field.checkIfWon()) {
        this->resetButton.setNeutralCoordinates(sf::IntRect(650, 0, 50, 50));
        this->resetButton.setPosition(sf::Vector2f(horizontalOffset + (50 * nWidth / 2) - 25, 25));
    }
}

// Render:
void Game::render() {
    this->bg.drawto(window);
    this->resetButton.drawTo(window);
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

// Reinitialize field:
void Game::reset() {
    this->resetButton.setNeutralCoordinates(sf::IntRect(600, 0, 50, 50));
    this->resetButton.setPosition(sf::Vector2f(horizontalOffset + (50 * nWidth / 2) - 25, 25));
    this->field.reset();
}

/* RESET BUTTON */
// Default Constructor:
ResetButton::ResetButton() {
}

ResetButton::ResetButton(Game* game) : game(game) {
    this->setTexture(TextureManager::get_texture("res/tile.png"));
    this->setNeutralCoordinates(sf::IntRect(600, 0, 50, 50));
    this->setPosition(sf::Vector2f(horizontalOffset + (50 * nWidth / 2) - 25, 25));
}

ResetButton::~ResetButton() {
}

// Virtual Overrides:
void ResetButton::onClick() {
    this->game->reset();
}

void ResetButton::onHover() {
}
