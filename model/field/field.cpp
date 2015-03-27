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
int Field::getFieldSize(){
    return this->field_height*this->field_width;
}

Cell* Field::getFieldMatrix(){
    return this->field_matrix;
}

Cell* Field::getFieldAt(int x, int y){
    return &field_matrix[x+y*field_width];
}

void Field::replaceCell(int x, int y, char newVolume){
    this->field_matrix[x+(this->field_width*y)] = newVolume;
}

