#include "Fruitz.hpp"
#include <cstdlib>
Fruitz::Fruitz(int x, int y)
    : Body(x,y,16,16)
{
}


Fruitz::~Fruitz()
{

}

Body Fruitz::getBody()
{
    return *this;
}

void Fruitz::draw(Screen& screen)
{
    for(int i = m_x; i < m_x+16 ;i++){
        for(int j = m_y; j < m_y+16 ; j++){
            screen.drawPixel(i,j,255,255,0);
        }
    }
}


void Fruitz::eaten()
{
    int x = rand() % 80;   
    int y = rand() % 45;
    m_x = x * 16;
    m_y = y * 16;

}