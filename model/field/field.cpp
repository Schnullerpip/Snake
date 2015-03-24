#include "field.h"

Field::Field(int width, int height){
    this->field_width = width;
    this->field_height = height;
    this->field_matrix = new Cell[width*height];
    for(int i=0;i<width*height;i++){
        field_matrix[i] = Cell('e');
    }
}

int Field::getFieldWidth(){
    return this->field_width;
}
int Field::getFieldHeight(){
    return this->field_height;
}

Cell* Field::getFieldMatrix(){
    return this->field_matrix;
}


void Field::replaceCell(int x, int y, char newVolume){
    this->field_matrix[this->field_width+(this->field_width*this->field_height)] = Cell(newVolume);
}

