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
void Controller::moveSnake(){
    int x=0, y=0;
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

}
