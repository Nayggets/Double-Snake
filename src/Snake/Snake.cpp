#include "Snake.hpp"

Snake::Snake(int x, int y, int dir)
{
    head = std::make_unique<HeadSnake>(x,y,dir);
    Corp = LinkedSnake();
}

Snake::~Snake()
{

}

void Snake::addBody()
{
    if(Corp.current != nullptr){
        std::cout << "coucou" << std::endl;
        LinkedSnake* r = &Corp;
        while(r->next != nullptr){
            r = r->next;
        }
        r->next = new LinkedSnake(r->current->createNext());
    }
    else{
        BodySnake s = head->createNext();
        Corp.current = new BodySnake(head->createNext());

    }
}


void Snake::draw(Screen& screen)
{
    head->draw(screen);

    if(Corp.current == nullptr){
        return;
    }

    LinkedSnake* r = &Corp;

    while(r->next != nullptr){
        r->current->draw(screen);
        r = r->next;
    }

    r->current->draw(screen);

}

void Snake::update(int x)
{


    int mooveForNext = head->update(x);
    if(Corp.current == nullptr){
        return;
    }

    LinkedSnake* r = &Corp;

    while(r != nullptr){
        mooveForNext = r->current->update(mooveForNext);
        r = r->next;
    }
}

bool Snake::checkCollideWithOther(Body b)
{
    if(head->collide(b)){
        return true;
    }
    else{
        return false;
    }
}

std::vector<Body> Snake::allBody()
{
    std::vector<Body> forCollision;
    forCollision.push_back(*head.get());
    if(Corp.current == nullptr){
        return forCollision;
    }

    LinkedSnake* r = &Corp;

    while(r != nullptr){
        forCollision.push_back(*r->current);
        r = r->next;
    }

    return forCollision;
}