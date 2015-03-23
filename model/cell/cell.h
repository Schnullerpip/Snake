#ifndef CELL_H
#define CELL_H
class Cell{
    char volume;//Inhalt der Zelle -> ist entweder NULL oder ein Charakter der ein Körperteil der Snake repräsentiert oder ein food
    public:
        char getVolume();
};
#endif
