#pragma once
#include <iostream>
#include "HeadSnake.hpp"
#include "BodySnake.hpp"

typedef struct LinkedSnake{
    BodySnake* current;
    LinkedSnake* next;
    LinkedSnake()
    {
        current = nullptr;
        next = nullptr;
    }
    LinkedSnake(BodySnake data)
    {
        current = new BodySnake(data);
        next = nullptr;
    }


} LinkedSnake_t;

class Snake{

    public:
        Snake(int x, int y, int dir);
        ~Snake();
        void update(int x);
        void draw(Screen& screen);
        void addBody();
        bool checkCollideWithOther(Body b);
        std::vector<Body> allBody();
    private:
        std::unique_ptr<HeadSnake> head;
        LinkedSnake_t Corp;
};

