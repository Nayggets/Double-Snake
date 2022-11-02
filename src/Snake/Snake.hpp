#pragma once
#include "HeadSnake.hpp"
#include "BodySnake.hpp"

class Snake{

    public:
        Snake(int x, int y, int dir);
        ~Snake();
        void update();
        void draw();

    private:
        std::unique_ptr<HeadSnake> head;
        LinkedSnake_t Corp;
};

typedef struct LinkedSnake{
    BodySnake current;
    LinkedSnake* next;
} LinkedSnake_t;