#include "HeadSnake.hpp"

HeadSnake::HeadSnake(int x, int y, int dir)
{
    this->x = x;
    this->y = y;
    this->lastmoove = dir;
    
}


void HeadSnake::update(int moove)
{
    if(lastmoove == 4){
        if(moove == 3){
            this->x++;
            lastmoove = moove;
        }
        else if(moove == 1){
            this->x--;
            lastmoove = moove;
        }
        else{
            this->y++;

        }
    }
    else if(lastmoove == 3){
        if(moove == 4){
            this->y++;
            lastmoove = moove;
        }
        else if(moove == 2){
            this->y--;
            lastmoove = moove;
        }
        else{
            this->x++;

        }
    }
    else if(lastmoove == 2){
        if(moove == 3){
            this->x++;
            lastmoove = moove;
        }
        else if(moove == 1){
            this->x--;
            lastmoove = moove;
        }
        else{
            this->y--;

        }

    }
    else{
        if(moove == 4){
            this->y++;
            lastmoove = moove;
        }
        else if(moove == 2){
            this->y--;
            lastmoove = moove;
        }
        else{
            this->x--;

        }
    }

}

void HeadSnake::draw()
{
    
}


