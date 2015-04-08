#include "TUI.h"
#include "iostream"
#include <pthread.h>

#define TOPLEFT "\u2554"
#define TOPRIGHT "\u2557\n"
#define BOTTOMLEFT "\u255A"
#define BOTTOMRIGHT "\u255D\n"

#define HORILINE "\u2550"
#define VERTILINE "\u2551"

#define DEBUG_SNAKE

/*GETTERS AND SETTERS*/
TUI::TUI(Controller* con){
    this->con = con;

    pthread_t inputThread;
    if(pthread_create(&inputThread, NULL,inputThreadRoutine, (void *)con)){
        std::cout << "unable to create inputThread..." << std::endl;
    }
}

/*GETTERS AND SETTERS*/
void TUI::setController(Controller* con){
    this->con = con;
}
Controller *TUI::getController(){
    return this->con;
}

/*INPUT THREAD ROUTINE!*/
void *inputThreadRoutine(void *arg){
    Controller * con = (Controller*)arg;
    char input;
    while(true){
        std::cin >> input;
        switch(input){
            case 'w':
                con->processInput('u');
                break;
            case 's':
                con->processInput('d');
                break;
            case 'a':
                con->processInput('l');
                break;
            case 'd':
                con->processInput('r');
                break;
        }
        std::cout << "input catched: " << input << std::endl;
    }
    return 0;
}

/*VIEW SPECIFIV FUNCTIONS*/
void TUI::printGamefield(){
    std::cout << "\x1B[2J\x1B[H"; //this should clear the console
    for(int i=0;i<this->con->getField().getFieldHeight(); ++i){
        for(int o=0;o<this->con->getField().getFieldWidth();++o){
            if(i==0){
                if(o==0){ std::cout << TOPLEFT;}
                else if(o==this->con->getField().getFieldWidth()-1){std::cout << TOPRIGHT;}
                else{std::cout << HORILINE;}
            }
            else if(i==this->con->getField().getFieldHeight()-1){
                    if(o==0){std::cout << BOTTOMLEFT;}
                    else if(o==this->con->getField().getFieldWidth()-1){std::cout << BOTTOMRIGHT;}
                    else{std::cout << HORILINE;}
            }
            else if(o==0){std::cout << VERTILINE;}
            else if(o==this->con->getField().getFieldWidth()-1){std::cout << VERTILINE <<"\n";}
            else{
                //std::cout << con->getField().getFieldMatrix()[o+i*con->getField().getFieldWidth()].getVolume();
                switch(this->con->getField().getFieldMatrix()[o+i*con->getField().getFieldWidth()].getVolume()){
                    case 'e':
                        std::cout << " ";
                        break;
                    case 'h':
                        switch(con->getSnake().getDirection()){
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
                        std::cout << "%";
                        break;
                    default:
                        std::cout << "d";
                        break;
                }
            }
        }
    }
    std::cout << "\nInsert Direction (w,a,s,d) andpress Rreturn" << std::endl;

#ifdef DEBUG_SNAKE
//std::cout << "\nposition head X: " << con->getSnake().getTailAt(0)->getX() << std::endl;
//std::cout << "position head Y: " << con->getSnake().getTailAt(0)->getY() << std::endl;
//std::cout << "\nposition food X: " << con->getFood().getPosition()->getX() << std::endl;
//std::cout << "position food Y: " << con->getFood().getPosition()->getY() << std::endl;
#endif
std::cout << "SCORE: " << con->getSnake().getTails().size() << std::endl;


}

