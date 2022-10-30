#pragma once

class SnakePart{

public:
    virtual void draw();
    virtual void update(int move); 

protected:
    int x,y;
    int lastmoove;
    int dir;
    SnakePart* nextPart;
};