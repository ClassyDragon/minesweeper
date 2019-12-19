#pragma once
#include <iostream>
#include <vector>
#include "State.h"
#include "Button.h"

class Menu : public State {
    public:
        // Default Constructor:
        Menu();

        // Update:
        void update(); // Pure virtual override

        // Render:
        void render(); // Pure virtual override

        // Return State:
        int getState();
    private:
        // Pointer to window:
        sf::RenderWindow* window;

        // Buttons:
        std::vector<Button*> buttons;
};
