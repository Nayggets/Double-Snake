#include "HeadSnake.hpp"
#include <iostream>

HeadSnake::HeadSnake(int x, int y, int dir)
    : SnakePart(x,y)
{
    this->m_x = x;
    this->m_y = y;
    this->m_lastmoove = dir;
    this->m_dir = dir;
}

HeadSnake::~HeadSnake()
{

}

int HeadSnake::update(int moove)
{
    
    int copyLast = m_lastmoove;
    if(m_dir == moove){
        m_lastmoove = moove;
        copyLast = moove;
        switch(m_dir)
        {
            case 4:
            {
                this->m_y -= 16;
                break;
            }
            case 3:
            {
                this->m_x += 16;
                break;
            }
            case 2:
            {
                this->m_y +=16;
                break;
            }
            case 1:
            {
                this->m_x -=16;
                break;
            }
        }
        return m_dir;
    }
    if(m_lastmoove == 4){
        if(moove == 3){
            this->m_x += 16;
            m_lastmoove = moove;
            m_dir = moove;
        }
        else if(moove == 1){
            this->m_x -= 16;
            m_lastmoove = moove;
            m_dir = moove;
        }
        else{
            this->m_y-=16;

        }
    }
    else if(m_lastmoove == 3){
        if(moove == 4){
            this->m_y -= 16;
            m_lastmoove = moove;
            m_dir = moove;
        }
        else if(moove == 2){
            this->m_y += 16;
            m_lastmoove = moove;
            m_dir = moove;
        }
        else{
            this->m_x += 16;

        }
    }
    else if(m_lastmoove == 2){
        if(moove == 3){
            this->m_x += 16;
            m_lastmoove = moove;
            m_dir = moove;
        }
        else if(moove == 1){
            this->m_x -= 16;
            m_lastmoove = moove;
            m_dir = moove;
        }
        else{
            this->m_y += 16;

        }

    }
    else{
        if(moove == 4){
            this->m_y-=16;
            m_lastmoove = moove;
            m_dir = moove;
        }
        else if(moove == 2){
            this->m_y+=16;
            m_lastmoove = moove;
            m_dir = moove;
        }
        else{
            this->m_x-=16;

        }
    }
    return copyLast;
}

void HeadSnake::draw(Screen& screen)
{
    for(int i = m_x ; i < m_x+16 ; i++){
        for(int j = m_y; j < m_y+16 ;j++){
            screen.drawPixel(i,j,255,0,0);
        }
    }
}


BodySnake HeadSnake::createNext()
{
    std::cout << m_dir << std::endl;
    if(m_dir == 4){
        return BodySnake(m_x,m_y+16,m_lastmoove);

    }
    else if(m_dir == 3){
        return BodySnake(m_x-16,m_y,m_lastmoove);
    }
    else if(m_dir == 2){
        return BodySnake(m_x,m_y-16,m_lastmoove);

    }
    else{
        return BodySnake(m_x+16,m_y,m_lastmoove);
    }
}