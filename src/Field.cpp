#include "Field.h"

// Default Constructor:
Field::Field() {
    init();
}

// Destructor:
Field::~Field() {
    mines.clear();
}

// Initialize and reset:
void Field::init() {
    isWon = false;
    srand(time(NULL));
    std::vector<int> hundredNumbers(nWidth * nHeight);
    std::vector<int> mineTiles;
    for (int i = 0; i < nWidth * nHeight; i++) {
        hundredNumbers[i] = i;
    }
    unsigned int numMines = (nWidth * nHeight) / 6;
    while (mineTiles.size() != numMines) {
        int j = rand() % hundredNumbers.size();
        mineTiles.push_back(hundredNumbers[j]);
        hundredNumbers.erase(hundredNumbers.begin() + j);
    }
    for (unsigned int i = 0; i < mineTiles.size(); i++) {
        int x = mineTiles[i] % nWidth;
        int y = mineTiles[i] / nWidth;
        // Add one to adjacent tiles:
        if (!isOutOfBounds(x - 1, y)) tiles[x - 1][y].incNumAdjacentMines();
        if (!isOutOfBounds(x - 1, y + 1)) tiles[x - 1][y + 1].incNumAdjacentMines();
        if (!isOutOfBounds(x - 1, y - 1)) tiles[x - 1][y - 1].incNumAdjacentMines();
        if (!isOutOfBounds(x + 1, y)) tiles[x + 1][y].incNumAdjacentMines();
        if (!isOutOfBounds(x + 1, y + 1)) tiles[x + 1][y + 1].incNumAdjacentMines();
        if (!isOutOfBounds(x + 1, y - 1)) tiles[x + 1][y - 1].incNumAdjacentMines();
        if (!isOutOfBounds(x, y + 1)) tiles[x][y + 1].incNumAdjacentMines();
        if (!isOutOfBounds(x, y - 1)) tiles[x][y - 1].incNumAdjacentMines();
        tiles[x][y] = Tile(TileType::MINE);
        mines.push_back(&tiles[x][y]);
    }
    for (int y = 0; y < nHeight; y++) {
        for (int x = 0; x < nWidth; x++) {
            if (tiles[x][y].getType() != TileType::MINE) {
                numbers.push_back(&tiles[x][y]);
            }
            tiles[x][y].setPosition(sf::Vector2f(
                        horizontalOffset + (50 * x),
                        verticalOffset + (50 * y)
                        )
                    );
        }
    }
}

void Field::reset() {
    mines.clear();
    numbers.clear();
    for (int y = 0; y < nHeight; y++) {
        for (int x = 0; x < nWidth; x++) {
            tiles[x][y] = Tile();
        }
    }
    init();
}

// Update:
void Field::update() {
}

void Field::checkWinCondition() {
    bool allNumbersRevealed = true;
    for (auto& i : this->numbers) {
        if (i->getState() != TileState::REVEALED) {
            allNumbersRevealed = false;
            break;
        }
    }
    if (allNumbersRevealed) {
        isWon = true;
    }
}

bool Field::checkIfWon() {
    return isWon;
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
            int tileType = tiles[x][y].onClick(mousePos);
            switch (tileType) {
                case TileType::MINE: if (tiles[x][y].getState() == TileState::HIDDEN) {
                                         for (auto& i : mines) {
                                             i->pow();
                                         }
                                         for (int y = 0; y < nHeight; y++) {
                                             for (int x = 0; x < nWidth; x++) {
                                                 tiles[x][y].reveal();
                                             }
                                         }
                                     }
                                     break;
                case TileType::VACANT: if (tiles[x][y].getState() == TileState::HIDDEN) {
                                           revealSurroundingTiles(x, y);
                                       }
                                       checkWinCondition();
                                       break;
                default: break;
            }
        }
    }
}

void Field::rightClick(sf::Vector2i mousePos) {
    for (int y = 0; y < nHeight; y++) {
        for (int x = 0; x < nWidth; x++) {
            int tileState = tiles[x][y].onRightClick(mousePos);
            switch (tileState) {
                case TileState::HIDDEN: tiles[x][y].flag();
                                        break;
                case TileState::REVEALED: break;
                case TileState::FLAGGED: tiles[x][y].unflag();
                                        break;
                default: break;
            }
        }
    }
}

// Reveal Surrounding Tiles:
void Field::revealSurroundingTiles(int x, int y) {
    this->tiles[x][y].reveal();
    sf::Vector2i current;
    if (this->tiles[x][y].getNumAdjacentMines() == 0) {
        std::queue<sf::Vector2i> surrounding;
        surrounding.push(sf::Vector2i(x + 1, y));
        surrounding.push(sf::Vector2i(x + 1, y + 1));
        surrounding.push(sf::Vector2i(x + 1, y - 1));
        surrounding.push(sf::Vector2i(x - 1, y));
        surrounding.push(sf::Vector2i(x - 1, y + 1));
        surrounding.push(sf::Vector2i(x - 1, y - 1));
        surrounding.push(sf::Vector2i(x, y + 1));
        surrounding.push(sf::Vector2i(x, y - 1));
        while (!surrounding.empty()) {
            current = surrounding.front();
            if (!isOutOfBounds(current)) {
                if (this->tiles[current.x][current.y].getState() != TileState::REVEALED) {
                    this->tiles[current.x][current.y].reveal();
                    if (this->tiles[current.x][current.y].getNumAdjacentMines() == 0) {
                        surrounding.push(sf::Vector2i(current.x + 1, current.y));
                        surrounding.push(sf::Vector2i(current.x + 1, current.y + 1));
                        surrounding.push(sf::Vector2i(current.x + 1, current.y - 1));
                        surrounding.push(sf::Vector2i(current.x - 1, current.y));
                        surrounding.push(sf::Vector2i(current.x - 1, current.y + 1));
                        surrounding.push(sf::Vector2i(current.x - 1, current.y - 1));
                        surrounding.push(sf::Vector2i(current.x, current.y + 1));
                        surrounding.push(sf::Vector2i(current.x, current.y - 1));
                    }
                }
                surrounding.pop();
            }
            else {
                surrounding.pop();
            }
        }
    }
}

// Check if indicies are out of bounds:
bool Field::isOutOfBounds(sf::Vector2i indicies) {
    if (indicies.x > nWidth - 1 || indicies.x < 0 || indicies.y > nHeight - 1 || indicies.y < 0)
        return true;
    return false;
}

bool Field::isOutOfBounds(int x, int y) {
    if (x > nWidth - 1 || x < 0 || y > nHeight - 1 || y < 0)
        return true;
    return false;
}
