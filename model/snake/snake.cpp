#include "snake.h"
#include <iostream>

/*CONSTRUCTOR*/
Snake::Snake(){
    Position * p = new Position(2, 2);
    this->tails.push_back(p);
    this->position_head = tails.at(0);
    this->taillength = 1;
    this->direction = 'd';
}

Position * Snake::getPositionHead(){
    return this->position_head;
}

int Snake::getTailLength(){
    return this->taillength;
}

std::vector<Position*> Snake::getTails(){
    return this->tails;
}

Position * Snake::getTailAt(int i){
    return this->tails.at(i);
}

void Snake::setTailAt(int i, int x, int y){
    this->tails.at(i)->setX(x);
    this->tails.at(i)->setY(y);
}

char Snake::getDirection(){
    return this->direction;
}

void Snake::setPositionHead(Position *p){
    this->position_head = p;
}

void Snake::incrementTailLength(){
    this->taillength++;
}

void Snake::eatAndGrow(Position *p){
    incrementTailLength();
    this->tails.insert(this->tails.begin(), p);
}

void Snake::setDirection(char newDirection){
    this->direction = newDirection;
}


