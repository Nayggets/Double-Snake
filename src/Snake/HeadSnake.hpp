#pragma once
#include "BodySnake.hpp"
#include "SnakePart.hpp"

class HeadSnake : public SnakePart{
    public:
        HeadSnake(int x, int y, int dir);
        ~HeadSnake();
        void draw(Screen& screen) override;
        int update(int move) override;
        BodySnake createNext();
};