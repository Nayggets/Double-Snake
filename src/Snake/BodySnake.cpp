#include "BodySnake.hpp"

BodySnake::BodySnake(int x, int y,int dir)
{
    this->x = x;
    this->y = y;
    this->dir = dir;
    this->lastmoove = dir;
}


void BodySnake::update(int move)
{

    if(move == 4){
        this->y++;
    }
    else if(move == 3){
        this->x++;
    }
    else if(move == 2){
        this->y--;
    }
    else{
        this->x--;
    }
    this->lastmoove = move;

}

void BodySnake::draw() 
{

}

