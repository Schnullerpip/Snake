#include "snake.h"

/*CONSTRUCTOR*/
Snake::Snake(Position p){
    this->tails.at(this->tails.size())=p;
    this->position_head = &(this->tails.at(this->tails.size()));
    this->taillength = 0;
}

Position * Snake::getPositionHead(){
    return this->position_head;
}

int Snake::getTailLength(){
    return this->taillength;
}

std::vector<Position> Snake::getTails(){
    return this->tails;
}

char Snake::getDirection(){
    return this->direction;
}

void Snake::setPositionHead(Position p){
    this->position_head = p;
}

void Snake::incrementTailLength(){
    this->taillength++;
}

void Snake::addToTail(Position p){
    incrementTailLength();
    this->tails.at(this->tails.size()) = p;
}


