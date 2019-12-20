#pragma once

// Screen pixel offset:
const int verticalOffset = 50;
const int horizontalOffset = 50;

// Field dimensions:
const int nWidth = 10;
const int nHeight = 10;

// Number of keys to poll:
const int numKeys = 2;

enum StateID {
    OVER = 0
};

// Key ID's:
enum Keys {
    LEFT_CLICK = 0,
    RIGHT_CLICK = 1
};

// State of keyboard key / mouse button:
enum KeyState {
    NOT_PRESSED = 0,
    PRESSED = 1
};

// Type of tile:
enum TileType {
    MINE = 0,
    VACANT = 1
};

// State of tile:
enum TileState {
    REVEALED = 0,
    HIDDEN = 1,
    FLAGGED = 2
};
