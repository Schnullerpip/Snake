#include "controller.h" 
#include <vector>


/*CONSTRUCTOR*/
Controller::Controller(Field f){
    Position p;
    this->snake = Snake(p);
    this->field = f;
    this->food = Food(p);
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
    old_x = this->snake.getPositionHead().getX();
    old_y = this->snake.getPositionHead().getY();
    tails.at(0).setX(old_x+x);
    tails.at(0).setY(old_y+y);

    /*now that all the bodyparts have been moved check if the head crushed against the gameframe or its own tail*/
    if(!checkForCollision(this->snake.getPositionHead())){
       return false; 
    } 


    /*now reorganize the field -> or bettre the fields cells -> their volume*/

    /*first reset every cell to empty -> 'e'*/
    for(int i=0;i<this->field.getFieldSize(); ++i){
        this->field.getFieldMatrix()[i].setVolume('e');
    }

    /*now set the correctcell to head -> h''*/
    this->field.getFieldMatrix()[this->snake.getPositionHead().getX()+(this->snake.getPositionHead().getY()*this->field.getFieldHeight())].setVolume('h');

    /*now give every cell that would have a tailpart a 't'*/
    Position iter;
    for(int i=1;i<this->snake.getTails().size(); i++){
        iter =this->snake.getTails().at(i);
        this->field.getFieldMatrix()[(iter.getX() +(this->field.getFieldHeight() * iter.getY()))].setVolume('t');
    }

    return true;
}




bool Controller::checkForCollision(Position p){
    if((p.getX()==0) || (p.getX()==this->field.getFieldWidth()) || (p.getY()==0) || (p.getY()==this->field.getFieldHeight())){
        return false;
    }
    std::vector<Position> tmp = this->snake.getTails();
    for(int i=3;i<tmp.size();++i){ //starting from first tail element (position 1) or else it would always fail
        if(p.compareTo(tmp.at(i))){
            return false;
        }        
    }
    return true;
}

void Controller::checkForEat(){
    if(this->snake.getPositionHead().compareTo(this->food.getPosition())){
        Position nextPosition;
        switch(this->snake.getDirection()){
            case 'u':
                nextPosition.setX(this->snake.getPositionHead().getX());
                nextPosition.setY(this->snake.getPositionHead().getY()-1);
                break;
            case 'd':
                nextPosition.setX(this->snake.getPositionHead().getX());
                nextPosition.setY(this->snake.getPositionHead().getY()+1);
                break;
            case 'r':
                nextPosition.setX(this->snake.getPositionHead().getX()+1);
                nextPosition.setY(this->snake.getPositionHead().getY());
                break;
            case 'l':
                nextPosition.setX(this->snake.getPositionHead().getX()-1);
                nextPosition.setY(this->snake.getPositionHead().getY());
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


