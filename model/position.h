#ifndef POSITION_H
#define POSITION_H
class Position{
    /*Position coordinates in the filed matrix - since its 2D we need x and y*/
    int x;
    int y;
    public:
        /*Constructor*/
        Position(int x=0, int y=0);
        /*Getters and Setters for the coordinates*/
        int getX();
        int getY();

        void setX(int x);
        void setY(int y);

        bool compareTo(Position p);
};
#endif
