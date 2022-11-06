#pragma once
#include "../Body2D/Body.hpp"
#include "../Screen_Manager/Screen.hpp"
#include <memory>
#include <vector>
class SnakePart : public Body{

public:
    SnakePart(int x,int y)
    : Body(x,y,16,16)
    {};
    virtual void draw(Screen& screen){};
    virtual int update(int move){return 0;}; 
    bool checkCollide(int x, int y)
    {
        if(m_x == x && m_y == y){
            return true;
        }
        else{
            return false;
        }
    };
    

protected:
    int m_lastmoove;
    int m_dir;
};