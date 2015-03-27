#include "food.h"

Food::Food(Position* p){
    this->pos = p;
}

Position* Food::getPosition(){
    return this->pos;
}

void Food::setPosition(Position* p){
    this->pos = p;
}

void Food::reposition(int new_x,int new_y){
    this->pos->setX(new_x);
    this->pos->setY(new_y);
}
