#include "MineSweeper.h"

// Default Constructor:
MineSweeper::MineSweeper() {
    // Load Textures:
    initTextures();

    // Initialize Window:
    this->window.create(sf::VideoMode(100 + (50 * nWidth), 100 + (50 * nHeight)), "MineSweeper");
    this->window.setFramerateLimit(20);

    // Create Menu:
    this->currentState.push(new Game(&this->window));
}

// Destructor:
MineSweeper::~MineSweeper() {
    delete this->currentState.top();
    currentState.pop();
}

// Init Functions:
void MineSweeper::initTextures() {
    TextureManager::load("res/tile.png");
    TextureManager::load("res/background.png");
}

void MineSweeper::initKeys() {
    for (int i = 0; i < numKeys; i++) {
        keyState[i] = KeyState::NOT_PRESSED;
    }
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
    this->updateInput();
    this->currentState.top()->update();
}

void MineSweeper::updateEvent() {
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed) {
            this->window.close();
        }
    }
}

void MineSweeper::updateInput() {
    // Left Mouse Click:
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (keyState[Keys::LEFT_CLICK] == KeyState::NOT_PRESSED) {
            keyState[Keys::LEFT_CLICK] = KeyState::PRESSED;
            currentState.top()->leftClick();
        }
    }
    else {
        keyState[Keys::LEFT_CLICK] = KeyState::NOT_PRESSED;
    }
    // Right Mouse Click:
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        if (keyState[Keys::RIGHT_CLICK] == KeyState::NOT_PRESSED) {
            keyState[Keys::RIGHT_CLICK] = KeyState::PRESSED;
            currentState.top()->rightClick();
        }
    }
    else {
        keyState[Keys::RIGHT_CLICK] = KeyState::NOT_PRESSED;
    }
}

// Render:
void MineSweeper::render() {
    window.clear();
    this->currentState.top()->render();
    window.display();
}
