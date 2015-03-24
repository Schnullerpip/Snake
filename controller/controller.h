#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/field/field.h"
#include "../model/food/food.h"
#include "../model/snake/snake.h"

class Controller{
    private:
        Snake snake;
        Field field;    //one gamefield
        Food food;      //only one food, same object can eba eaten several times no need for creating many foods that have the same attributes anyway (except for position of course, but position can be set by a setter easily instead)

    public:
        /*CONSTRICTOR*/
        Controller(Field f=Field);

        /*GETTERS AND SETTERS*/
        Snake getSnake();
        Field getField();
        Food geFood();

        void setField(Field f);
        void setFood(Food f);


        /*IMPORTANT GAME FUNCTIONS*/
        void moveSnake();
};
#endif
