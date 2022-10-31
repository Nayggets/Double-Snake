#include "BodySnake.hpp"

BodySnake::BodySnake(int x, int y,SnakePart parent,int dir)
{
    parent->nextPart = this;
    this->x = x;
    this->y = y;
    this->dir = dir;
    this->lastmoove = dir;
}


void BodySnake::update(int move)
{
    if(this->nextPart != nullptr){
        this->nextPart->update(this->lastmoove);
    }
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

bool BodySnake::check_collide(SnakePart other)
{
    if(this->x == other.x && this->y == other.y){
        return true;
    }
    else{
        return false;
    }
}