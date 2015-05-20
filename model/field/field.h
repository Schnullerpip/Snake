#ifndef FIELD_H

#include "../cell/cell.h"
class Field{
    private:
        int field_width;
        int field_height;
        Cell *field_matrix;
    public:

        /*CONSTRUCTOR*/
        Field(int width=30, int height=18);

        int getFieldWidth();
        int getFieldHeight();
        int getFieldSize();
        Cell * getFieldMatrix();
        Cell * getFieldAt(int x, int y);

        void replaceCell(int x, int y, char newVolume);
        void cleanUp();
};
#endif
