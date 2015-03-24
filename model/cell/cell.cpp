#include "cell.h"

Cell::Cell(char v){
    this->volume = v;
}

char Cell::getVolume(){
    return this->volume;
}
void Cell::setVolume(char v){
    this->volume = v;
}
