#include "Field.h"

// Default Constructor:
Field::Field() {
    for (int y = 0; y < nHeight; y++) {
        for (int x = 0; x < nWidth; x++) {
            tiles[x][y].setPosition(sf::Vector2f(
                        horizontalOffset + (50 * x),
                        verticalOffset + (50 * y)
                        )
                    );
        }
    }
}

// Update:
void Field::update() {
}

// Draw:
void Field::drawto(sf::RenderWindow* window) {
    // Draw all tiles:
    for (int y = 0; y < nHeight; y++) {
        for (int x = 0; x < nWidth; x++) {
            tiles[x][y].drawto(window);
        }
    }
}

// Poll a Left Click:
void Field::leftClick(sf::Vector2i mousePos) {
    for (int y = 0; y < nHeight; y++) {
        for (int x = 0; x < nWidth; x++) {
            tiles[x][y].onClick(mousePos);
        }
    }
}
