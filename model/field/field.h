#ifndef FIELD_H

#include "../cell/cell.h"
class Field{
    private:
        int field_width;
        int field_height;
        Cell *field_matrix;
    public:

        /*CONSTRUCTOR*/
        Field(int width=20, int height=30);

        int getFieldWidth();
        int getFieldHeight();
        int getFieldSize();
        Cell * getFieldMatrix();

        void replaceCell(int x, int y, char newVolume);
};
#endif
