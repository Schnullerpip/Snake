

#include "controller/controller.h"
#include "view/TUI.h"
#include <iostream>

#include <unistd.h>

int main(){

    unsigned int gamespeed = 100000;
    Controller controller;
    TUI tui= TUI(&controller);

    std::cout << "field size: " << controller.getField().getFieldSize() << std::endl;
    std::cout << "field height: " << controller.getField().getFieldHeight() << std::endl;
    std::cout << "field width: " << controller.getField().getFieldWidth() << std::endl;

    while(controller.moveSnake()){
        controller.checkForEat();
        tui.printGamefield();
        usleep(gamespeed);
    }


    std::cout << "Thanks for playing" << std::endl;




}
