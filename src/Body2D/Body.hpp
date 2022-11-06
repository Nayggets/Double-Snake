#pragma once
class Body{

    public:
        Body(int x, int y,int length, int width);
        ~Body();
        bool collide(Body b);

    private:
        int m_length,m_width;
    protected:
        int m_x,m_y;

    protected:

};