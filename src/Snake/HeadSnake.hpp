#pragma once
#include "SnakePart.hpp"

class HeadSnake : public SnakePart{
    public:
        HeadSnake(SnakePart parent,int dir);
        ~HeadSnake();
        void draw() override;
        void update(int move) override;

};