
#include "controller/controller.h"
#include "view/TUI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

/*helpfunction for score*/
std::vector<std::string> & split(const std::string &s, char delim, std::vector<std::string> &elems){
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)){
        elems.push_back(item);
    }
    return elems;
}

int main(){

    unsigned int gamespeed = 115000;
    Controller controller;
    TUI tui= TUI(&controller);

#ifdef DEBUG 
    std::cout << "field size: " << controller.getField().getFieldSize() << std::endl;
    std::cout << "field height: " << controller.getField().getFieldHeight() << std::endl;
    std::cout << "field width: " << controller.getField().getFieldWidth() << std::endl;
#endif

    while(controller.moveSnake()){
        controller.checkForEat();
        tui.printGamefield();
        usleep(gamespeed);
    }

    /*cleanup*/
    controller.getField().cleanUp();



    tui.endInputThread();


    std::cout << "Thanks for playing" << std::endl;

    char* path;
    if((path = strcat(getenv("HOME"), "/.snake/score.txt")) == NULL){
        path = strcat(getpwuid(getuid())->pw_dir, "/.snake/score.txt");
    }
    std::ifstream i_score (path);
    if(i_score.is_open()){
        std::string line, contestant;
        getline(i_score, line);
        i_score.close();
        std::vector<std::string> name_and_score;
        split(line, ';', name_and_score);

        if((controller.getSnake().getTailLength()) > atoi(name_and_score.at(1).c_str())){
            std::ofstream o_score (path);
            std::cout << "Congratulations, you broke the local record!\nInsert w,a,s,or d\n";
            std::string dummy;
            getline(std::cin,dummy);
            std::cout << "Previous Highscore was:\t'" << name_and_score.at(0) << "' with -->" << name_and_score.at(1) << "<--\nYour Score is: -->" << controller.getSnake().getTailLength() << "<--\n\nPlease insert your Name:\n";

            getline(std::cin, contestant);
            o_score << contestant << ";" << controller.getSnake().getTailLength();
            o_score.close();
        }
    }
}
