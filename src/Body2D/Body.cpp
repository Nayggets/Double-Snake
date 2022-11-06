#include "Body.hpp"


Body::Body(int x, int y, int length, int width)
{
    m_x = x;
    m_y = y;
    m_length = length;
    m_width = width;
}

Body::~Body()
{

}

bool Body::collide(Body b)
{
    if(m_x < b.m_x + b.m_width && m_x + m_width > b.m_x && m_y < b.m_y + b.m_length && m_length + m_y > b.m_y){
        return true;
    }
    else{
        return false;
    }
}