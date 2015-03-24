#include "food.h"

Food::Food(){}

Position Food::getPosition(){
    return this->pos;
}

void Food::setPosition(Position p){
    this->pos = p;
}
