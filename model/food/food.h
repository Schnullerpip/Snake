#ifndef FOOD_H
#define FOOD_H

#include "../position.h"
class Food{
    private:
        Position* pos;

    public:
        /*CONSTRUCTOR*/
        Food(Position* p= new Position());

        Position* getPosition();
        void setPosition(Position* p);
        void reposition(int fieldWidth, int fieldHeight);

};
#endif
