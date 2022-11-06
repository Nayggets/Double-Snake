#include "SnakePart.hpp"
#pragma once

class BodySnake : public SnakePart{
    public:
        BodySnake(int x, int y,int dir);
        ~BodySnake();
        void draw(Screen& screen) override;
        int update(int move) override;
        BodySnake createNext();
};