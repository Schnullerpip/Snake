#ifndef CELL_H
#define CELL_H

class Cell{
    public:
        /*CONSTRUCTOR*/
        Cell(char volume='e');
        char getVolume();
        void setVolume(char v);
    private:
        char volume;
            /* e == empty
             * h == head
             * t == tail
             * f == food
             * o == omnom -> foodInTail*/
};
#endif
