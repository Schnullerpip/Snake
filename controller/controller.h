#ifndef CONTROLLER_SNAKE_H
#define CONTROLLER_SNAKE_H

#include "../model/field/field.h"
#include "../model/food/food.h"
#include "../model/snake/snake.h"
#include <stdlib.h>
#include "../lock_distributor/lock_distributor.h"

class Controller{
    private:
        Snake snake;
        Field field;    //one gamefield
        Food food;      //only one food, same object can bea eaten several times no need for creating many foods that have the same attributes anyway (except for position of course, but position can be set by a setter easily instead)
        lock_distributor lockdistributor;
        

    public:
        /*CONSTRICTOR*/
        Controller(Field f=Field());

        /*GETTERS AND SETTERS*/
        Snake getSnake();
        Field getField();
        Food getFood();
        lock_distributor getLockDistributor();

        void setField(Field &f);
        void setFood(Food &f);
        void setSnake(Snake &s);

        /*IMPORTANT GAME FUNCTIONS*/
        bool moveSnake(); //returns false if snake hit a wall or its own tail
        bool checkForCollision(); //called by moveSnake
        void findNewFoodLocation();
        void checkForEat(); //check if head position is equal to position of current food and repositions it if snake has had another meal
        void processInput(char newDirection); //will be called by view after input was catched
        bool isCompliment(char direction);

};
#endif
