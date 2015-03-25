#include "controller.h" 

/*CONSTRUCTOR*/
Controller::Controller(Field f){
    this->field = f;
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


/*IMPORTANT GAME FUNCTIONS*/
bool Controller::moveSnake(){
    int x=0, y=0;
    int old_x, old_y;

    switch(this->snake.getDirection()){
        case 'u': //up
            y=1;
            break;
        case 'd': //down
            y=-1;
            break;
        case 'l': //left
            x=-1;
            break;
        case 'r': //right
            x=1;
            break;
    }

    /*reorganize the entire tails vector*/
    for(int i=0;i<this->snake.getTails().size(); ++i){
        old_x = this->snake.getTails().at(i).getX();
        old_y = this->snake.getTails().at(i).getY();
        this->snake.getTails().at(i).setX(old_x+x)
        this->snake.getTails().at(i).setY(old_y+y)
    }

}

bool Controller::checkForCollision(Position& p){
    if((p.getX()==0) || (p.getX()==this->field.getWidth()) || (p.getY()==0) || (p.getY()==this->field.getHeight())){
        return false;
    }
    vector<Position> * tmp = &(this->snake.getTails());
    for(int i=0;i<tmp.size();++i){
        if(p.compareTo(tmp.at(i))){
            return false;
        }        
        return true;
    }
}

void Controller::checkForEat(){
    if(this->snake.getPositionHead().compareTo(this->food.getPosition())){
        //head is on field food
        this->food.reposition();
    }
}


void Controller::processInput(char newDirection){
    this->snake.setDirection(newDirection);
}


