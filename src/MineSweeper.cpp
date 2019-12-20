#include "MineSweeper.h"

// Default Constructor:
MineSweeper::MineSweeper() {
    // Load Textures:
    initTextures();

    // Initialize Window:
    this->window.create(sf::VideoMode(1000, 1000), "MineSweeper");
    this->window.setFramerateLimit(20);

    // Create Menu:
    this->currentState.push(new Game(&this->window));
}

// Init Functions:
void MineSweeper::initTextures() {
    TextureManager::load("res/tile.png");
    TextureManager::load("res/background.png");
}

// Game Loop:
void MineSweeper::startGame() {
    while (this->window.isOpen()) {
        this->update();
        this->render();
    }
}

// Updates:
void MineSweeper::update() {
    this->updateEvent();
    this->currentState.top()->update();
}

void MineSweeper::updateEvent() {
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed) {
            this->window.close();
        }
    }
}

// Render:
void MineSweeper::render() {
    window.clear();
    this->currentState.top()->render();
    window.display();
}
