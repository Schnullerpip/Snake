#include "TUI.h"
#include "iostream"

/*GETTERS AND SETTERS*/
TUI::TUI(Controller con){
    this->con = con;
}

/*GETTERS AND SETTERS*/
void TUI::setController(Controller con){
    this->con = con;
}
Controller TUI::getController(){
    return this->con;
}

/*VIEW SPECIFIV FUNCTIONS*/
void TUI::printGamefield(){
    std::cout << "\x1B[2J\x1B[H"; //this should clear the console
    for(int i=0, o=0;i<this->con.getField().getFieldSize(); ++i){
        switch(this->con.getField().getFieldMatrix()[i].getVolume()){
            case 'e':
                std::cout << " ";
                break;
            case 'h':
                std::cout << "H";
                break;
            case 't':
                std::cout << "O";
                break;
            case 'f':
                std::cout << "F";
                break;
            default:
                std::cout << " ";
                break;

        }
        o++;
        if(o == (this->con.getField().getFieldSize()-1)){
            std::cout << "\n";
            o=0;
        }
    }
}

