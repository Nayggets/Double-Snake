#pragma once
#include <memory>
#include <vector>
class SnakePart{

public:
    virtual void draw(){};
    virtual void update(int move){}; 

protected:
    int x,y;
    int lastmoove;
    int dir;
};