/* ____________ State Class ______________ */
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class State {
    public:
        State();
        virtual ~State() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual int getState() = 0;
        virtual void leftClick() = 0;
        virtual void rightClick() = 0;
    protected:
};
