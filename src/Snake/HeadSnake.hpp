#pragma once
#include "SnakePart.hpp"

class HeadSnake : public SnakePart{
    public:
        HeadSnake(int x, int y, int dir);
        ~HeadSnake();
        void draw() override;
        void update(int move) override;
        bool check_collide(SnakePart other) override;
};