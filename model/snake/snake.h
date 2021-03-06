#ifndef SNAKE_DATA_H
#define SNAKE_DATA_H

#include "../position.h"
#include <vector>

class Snake{
    private:
        Position* position_head;
        int taillength;
        std::vector<Position*> tails;
        char direction;
    public:
        /*CONSTRUCTOR*/
        Snake();

        /*GETTERS AND SETTERS*/
        Position * getPositionHead();
        int getTailLength();
        std::vector<Position*> getTails();
        Position * getTailAt(int i);
        char getDirection();

        void setTailAt(int i, int x, int y);
        void setPositionHead(Position * p);
        void eatAndGrow(Position* p);
        void incrementTailLength();
        void setDirection(char newDirection='u');
};
#endif
