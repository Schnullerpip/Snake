

#include "controller/controller.h"
#include "view/TUI.h"
#include <iostream>

#include <unistd.h>

int main(){

    unsigned int gamespeed = 1000;
    Controller controller;
    TUI tui = TUI(controller);

    while(controller.moveSnake()){
        tui.printGamefield();
        usleep(gamespeed);
    }


    std::cout << "Thanks for playing" << std::endl;




}
