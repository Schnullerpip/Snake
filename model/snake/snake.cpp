#include "snake.h"

/*CONSTRUCTOR*/
Snake::Snake(Position head){
    this->tails.at(0)=head;
    this->position_head = this->tails.at(0);
    this->taillength = 0;
}

Position Snake::getPositionHead(){
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

void Snake::eatAndGrow(Position p){
    incrementTailLength();
    this->tails.insert(this->tails.begin(), p);
}

void Snake::setDirection(char newDirection){
    this->direction = newDirection;
}


