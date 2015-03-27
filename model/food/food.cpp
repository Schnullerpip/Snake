#include "food.h"
#include "stdlib.h"

Food::Food(Position* p){
    this->pos = p;
}

Position* Food::getPosition(){
    return this->pos;
}

void Food::setPosition(Position* p){
    this->pos = p;
}

void Food::reposition(int fieldWidth,int fieldHeight){
    int new_x, new_y;

    new_x = rand() % fieldWidth;
    new_y = rand() % fieldHeight;

    this->pos->setX(new_x);
    this->pos->setY(new_y);
}
