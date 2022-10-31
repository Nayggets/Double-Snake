#pragma once

class SnakePart{

public:
    virtual void draw();
    virtual void update(int move); 
    bool void check_collide(SnakePart other);

protected:
    int x,y;
    int lastmoove;
    int dir;
    SnakePart* nextPart;
};