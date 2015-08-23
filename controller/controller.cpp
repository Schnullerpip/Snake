#include "controller.h" 
#include <vector>
#include <iostream>

#include <time.h>


/*CONSTRUCTOR*/
Controller::Controller(Field f){
    Position *p = new Position(2, 2);
    this->snake.setPositionHead(p);
    this->field = f;

    srand(time(0));
    findNewFoodLocation();
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
lock_distributor Controller::getLockDistributor(){
    return this->lockdistributor;
}

void Controller::setField(Field &f){ //SHOULD NEVER BE NEEDED
    this->field = f;
}
void Controller::setFood(Food &f){
    this->food = f;
}
void Controller::setSnake(Snake &s){
    this->snake = s;
}


/*IMPORTANT GAME FUNCTIONS*/
bool Controller::moveSnake(){
    int x=0, y=0;
    int old_x, old_y;

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
    for(int i=snake.getTails().size()-1;i>0; --i){
        /*igve each bodypart-position the values of its predecent bodypart-position - this way the entire tail follows the head*/
        snake.setTailAt(i, snake.getTailAt(i-1)->getX(), snake.getTailAt(i-1)->getY());
    }
    
    /*when the entire tail has followed up to the head, then finally change the heads position*/
    old_x =snake.getTailAt(0)->getX();
    old_y =snake.getTailAt(0)->getY();

    //std::cout << "beforex: " << snake.getTailAt(0)->getX() << std::endl;
    //std::cout << "beforey: " << snake.getTailAt(0)->getY() << std::endl;
    snake.setTailAt(0,old_x+x, old_y+y);

    /*now that all the bodyparts have been moved check if the head crushed against the gameframe or its own tail*/
    if(!checkForCollision()){
       return false; 
    } 

    /*now reorganize the field -> or bettre the fields cells -> their volume*/

    /*first reset each cell to empty -> 'e'*/
    for(int i=0;i<this->field.getFieldSize(); ++i){
        this->field.getFieldMatrix()[i].setVolume('e');
    }

    /*now set the correct position for the food*/
    this->field.replaceCell(food.getPosition()->getX(), food.getPosition()->getY(), 'f');

    /*now set all the tails*/
    Position *iter;
    for(unsigned int i=1;i<this->snake.getTails().size(); i++){
        iter =snake.getTailAt(i);
        this->field.replaceCell(iter->getX(),iter->getY(),'t');
    }
    /*now set the correctcell to head -> 'h'*/
    this->field.replaceCell(snake.getTailAt(0)->getX(),snake.getTailAt(0)->getY(), 'h');

    return true;
}




bool Controller::checkForCollision(){
    Position *p = this->snake.getTailAt(0);
    /*first check for collision with wall*/
    if((p->getX()==0) || (p->getX()==this->field.getFieldWidth()-1) || (p->getY()==0) || (p->getY()==this->field.getFieldHeight()-1)){
        return false;
    }
    /*now check for collision with tail*/
    for(unsigned int i=1;i<this->snake.getTails().size();++i){ //starting from first tail element (position 1) or else it would always fail
        if(p->compareTo(this->snake.getTailAt(i))){
            return false;
        }        
    }
    return true;
}


void Controller::findNewFoodLocation(){
    int new_x=0, new_y=0;
    bool free;

    do{
        free = true;
        new_x = rand() % field.getFieldWidth()-2;
        new_y = rand() % field.getFieldHeight()-2;

        if((new_x<=1) || (new_x>=field.getFieldWidth()) || (new_y <=1) || (new_y>=field.getFieldHeight()) ){free=false;continue;}

        for(unsigned int i=0;i<snake.getTails().size(); ++i){
            if(new_x == snake.getTails()[i]->getX() && new_y == snake.getTails()[i]->getY()){
                free = false;
                break;
            }
        }
    }while(!free);
    this->food.reposition(new_x, new_y);
}

void Controller::checkForEat(){
    Position * dereferencedHead = this->snake.getTailAt(0);
    if(dereferencedHead->compareTo(this->food.getPosition())){
        Position* nextPosition = new Position();
        switch(this->snake.getDirection()){
            case 'u':
                nextPosition->setX(dereferencedHead->getX());
                nextPosition->setY(dereferencedHead->getY()-1);
                break;
            case 'd':
                nextPosition->setX(dereferencedHead->getX());
                nextPosition->setY(dereferencedHead->getY()+1);
                break;
            case 'r':
                nextPosition->setX(dereferencedHead->getX()+1);
                nextPosition->setY(dereferencedHead->getY());
                break;
            case 'l':
                nextPosition->setX(dereferencedHead->getX()-1);
                nextPosition->setY(dereferencedHead->getY());
                break;
        }
        //head is on field food
        this->snake.eatAndGrow(nextPosition);
        findNewFoodLocation();
    }
}


void Controller::processInput(char newDirection){
    this->lockdistributor.getLock();
    if(!isCompliment(newDirection))
        this->snake.setDirection(newDirection);
    this->lockdistributor.freeLock();
}

bool Controller::isCompliment(char direction){
    char dir = this->snake.getDirection();

    if(dir == 'u' && direction == 'd')return true;
    if(dir == 'd' && direction == 'u')return true;
    if(dir == 'l' && direction == 'r')return true;
    if(dir == 'r' && direction == 'l')return true;

    return false;
}


