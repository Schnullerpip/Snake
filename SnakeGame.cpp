

#include "controller/controller.h"
#include "view/TUI.h"
#include <iostream>

#include <unistd.h>

int main(){

    unsigned int gamespeed = 150000;
    Controller controller;
    TUI tui= TUI(&controller);

//    std::cout << "field size: " << controller.getField().getFieldSize() << std::endl;
//    std::cout << "field height: " << controller.getField().getFieldHeight() << std::endl;
//    std::cout << "field width: " << controller.getField().getFieldWidth() << std::endl;

    while(controller.moveSnake()){
        std::cout << "moved snake"<< std::endl;
        controller.checkForEat();
        std::cout << "checkedForEat"<< std::endl;
        tui.printGamefield();
        std::cout << "printed Gamefield"<< std::endl;
        usleep(gamespeed);
        std::cout << "finished sleeping"<< std::endl;
    }


    std::cout << "Thanks for playing" << std::endl;




}
