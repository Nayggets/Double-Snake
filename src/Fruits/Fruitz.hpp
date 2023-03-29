#pragma once

#include "../Body2D/Body.hpp"
#include "../Screen_Manager/Screen.hpp"


class Fruitz : public Body{

    public:
        Fruitz(int x, int y);
        ~Fruitz();
        Body getBody();
        void draw(Screen& screen);
        void eaten();

};