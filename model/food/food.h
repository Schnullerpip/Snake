#ifndef FOOD_H
#define FOOD_H

#include "../position.h"
class Food{
    private:
        Position pos;

    public:
        /*CONSTRUCTOR*/
        Food();

        Position getPosition();
        void setPosition(Position p);

};
#endif
