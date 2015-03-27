#include "TUI.h"
#include "iostream"

#define TOPLEFT "\u2554"
#define TOPRIGHT "\u2557\n"
#define BOTTOMLEFT "\u255A"
#define BOTTOMRIGHT "\u255D\n"

#define HORILINE "\u2550"
#define VERTILINE "\u2551"

#define DEBUG_SNAKE

/*GETTERS AND SETTERS*/
TUI::TUI(const Controller& con){
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
    for(int i=0;i<this->con.getField().getFieldHeight(); ++i){
        for(int o=0;o<this->con.getField().getFieldWidth();++o){
            if(i==0){
                if(o==0){ std::cout << TOPLEFT;}
                else if(o==this->con.getField().getFieldWidth()-1){std::cout << TOPRIGHT;}
                else{std::cout << HORILINE;}
            }
            else if(i==this->con.getField().getFieldHeight()-1){
                    if(o==0){std::cout << BOTTOMLEFT;}
                    else if(o==this->con.getField().getFieldWidth()-1){std::cout << BOTTOMRIGHT;}
                    else{std::cout << HORILINE;}
            }
            else if(o==0){std::cout << VERTILINE;}
            else if(o==this->con.getField().getFieldWidth()-1){std::cout << VERTILINE <<"\n";}
            else{
                switch(this->con.getField().getFieldMatrix()[o+i*con.getField().getFieldWidth()].getVolume()){
                    case 'e':
                        std::cout << " ";
                        break;
                    case 'h':
                        switch(con.getSnake().getDirection()){
                            case 'u':
                                std::cout << "V";
                                break;
                            case 'd':
                                std::cout << "A";
                                break;
                            case 'r':
                                std::cout << "<";
                                break;
                            case 'l':
                                std::cout << ">";
                                break;
                        }
                        break;
                    case 't':
                        std::cout << "O";
                        break;
                    case 'f':
                        std::cout << "F";
                        break;
                    default:
                        std::cout << "d";
                        break;
                }
            }
        }
    }

#ifdef DEBUG_SNAKE
Position *pu = con.getSnake().getPositionHead();
Position p = *pu;
std::cout << "\nposition head X: " << p.getX() << std::endl;
std::cout << "position head Y: " << p.getY() << std::endl;
std::cout << "position head: " << p.getY()* con.getField().getFieldWidth() + p.getX() << std::endl;
std::cout << "adress of field: " << con.getField().getFieldMatrix() << std::endl;
#endif


}

