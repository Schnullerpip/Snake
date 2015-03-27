#ifndef TUI_VIEW_SNAKE_H
#define TUI_VIEW_SNAKE_H

#include "../controller/controller.h"
class TUI{
    private:
        Controller con;
    public:
        /*CONSTRUCTOR*/
        TUI(const Controller& con);

        /*GETTERS AND SETTERS*/
        void setController(Controller c);
        Controller getController();


        /*VIEW SPECIFIC FUNCTIONS*/
        void printGamefield();



};
#endif
