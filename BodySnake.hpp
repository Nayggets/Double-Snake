#include "SnakePart.hpp"
#pragma once

class BodySnake : public SnakePart{
    public:
        BodySnake(SnakePart parent,int dir);
        ~BodySnake();
        void draw() override;
        void update(int move) override;
    
};