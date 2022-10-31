#include "SnakePart.hpp"
#pragma once

class BodySnake : public SnakePart{
    public:
        BodySnake(int x, int y,SnakePart parent,int dir);
        ~BodySnake();
        void draw() override;
        void update(int move) override;
        bool check_collide(SnakePart other) override;

};