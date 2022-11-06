#include "BodySnake.hpp"

BodySnake::BodySnake(int x, int y,int dir)
    : SnakePart(x,y)
{
    this->m_x = x;
    this->m_y = y;
    this->m_dir = dir;
    this->m_lastmoove = dir;
}

BodySnake::~BodySnake()
{

}


int BodySnake::update(int move)
{
    int copyLast = m_lastmoove;
    if(move == 4){
        this->m_y -= 16;
    }
    else if(move == 3){
        this->m_x += 16;
    }
    else if(move == 2){
        this->m_y += 16;
    }
    else{
        this->m_x -= 16;
    }
    this->m_lastmoove = move;
    this->m_dir = move;
    return copyLast;
}

void BodySnake::draw(Screen& screen) 
{
    for(int i = m_x ; i < m_x+16 ; i++){
        for(int j = m_y; j < m_y+16 ;j++){
            screen.drawPixel(i,j,0,255,0);
        }
    }
}

BodySnake BodySnake::createNext()
{
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
