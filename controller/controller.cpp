#include "controller.h" 
#include <vector>
#include <iostream>


/*CONSTRUCTOR*/
Controller::Controller(Field f){
    Position *p = new Position(2, 2);
    this->snake.setPositionHead(p);
    this->field = f;
    this->food.setPosition(p);
}

/*GETTERS AND SETTERS*/
Snake Controller::getSnake(){
    return this->snake;
}
Field Controller::getField(){
    return this->field;
}
Food Controller::getFood(){
    return this->food;
}

void Controller::setField(Field f){ //SHOULD NEVER BE NEEDED
    this->field = f;
}
void Controller::setFood(Food f){
    this->food = f;
}
void Controller::setSnake(Snake s){
    this->snake = s;
}


/*IMPORTANT GAME FUNCTIONS*/
bool Controller::moveSnake(){
    int x=0, y=0;
    int old_x, old_y;
    std::vector<Position> tails = this->snake.getTails();
    /*This pointer will be needed a lot so for reducing the effort of calling this->snake... multiple times here it is*/
    Position *dereferencedHead = this->snake.getPositionHead();

    switch(this->snake.getDirection()){
        case 'u': //up
            y=-1;
            break;
        case 'd': //down
            y=1;
            break;
        case 'l': //left
            x=-1;
            break;
        case 'r': //right
            x=1;
            break;
    }

    /*reorganize the entire tails vector*/
    for(int i=tails.size()-1;i>0; --i){
        /*igve each bodypart-position the values of its predecent bodypart-position - this way the entire tail follows the head*/
        tails.at(i).setX(tails.at(i-1).getX());
        tails.at(i).setY(tails.at(i-1).getY());
    }
    
    /*when the entire tail has followed up to the head, then finally change the heads position*/
    old_x =dereferencedHead->getX();
    old_y =dereferencedHead->getY();
    tails.at(0).setX(old_x+x);
    tails.at(0).setY(old_y+y);
    

    /*now that all the bodyparts have been moved check if the head crushed against the gameframe or its own tail*/
    if(!checkForCollision()){
       return false; 
    } 

    /*now reorganize the field -> or bettre the fields cells -> their volume*/

    /*first reset every cell to empty -> 'e'*/
    for(int i=0;i<this->field.getFieldSize(); ++i){
        this->field.getFieldMatrix()[i].setVolume('e');
    }

    /*now set the correctcell to head -> h''*/
    this->field.getFieldMatrix()[dereferencedHead->getX()+(dereferencedHead->getY()*this->field.getFieldWidth())].setVolume('h');

    /*now give every cell that has a tailpart a 't'*/
    Position *iter;
    for(unsigned int i=1;i<this->snake.getTails().size(); i++){
        iter =&(this->snake.getTails().at(i));
        this->field.getFieldMatrix()[(iter->getX() +(this->field.getFieldHeight() * iter->getY()))].setVolume('t');
    }
    return true;
}




bool Controller::checkForCollision(){
    Position p = *(this->snake.getPositionHead());
    if((p.getX()==0) || (p.getX()==this->field.getFieldWidth()) || (p.getY()==0) || (p.getY()==this->field.getFieldHeight())){
        return false;
    }
    std::vector<Position> tmp = this->snake.getTails();
    for(unsigned int i=3;i<tmp.size();++i){ //starting from first tail element (position 1) or else it would always fail
        if(p.compareTo(tmp.at(i))){
            return false;
        }        
    }
    return true;
}

void Controller::checkForEat(){
    Position * dereferencedHead = this->snake.getPositionHead();
    if(dereferencedHead->compareTo(this->food.getPosition())){
        Position nextPosition;
        switch(this->snake.getDirection()){
            case 'u':
                nextPosition.setX(dereferencedHead->getX());
                nextPosition.setY(dereferencedHead->getY()-1);
                break;
            case 'd':
                nextPosition.setX(dereferencedHead->getX());
                nextPosition.setY(dereferencedHead->getY()+1);
                break;
            case 'r':
                nextPosition.setX(dereferencedHead->getX()+1);
                nextPosition.setY(dereferencedHead->getY());
                break;
            case 'l':
                nextPosition.setX(dereferencedHead->getX()-1);
                nextPosition.setY(dereferencedHead->getY());
                break;
        }
        //head is on field food
        this->snake.eatAndGrow(nextPosition);
        this->food.reposition(this->field.getFieldWidth(), this->field.getFieldHeight());
    }
}


void Controller::processInput(char newDirection){
    this->snake.setDirection(newDirection);
}


