#ifndef TUI_VIEW_SNAKE_H
#define TUI_VIEW_SNAKE_H

#include "../controller/controller.h"
/*INPUT THREAD ROUTINE!*/
void *inputThreadRoutine(void *arg);


class TUI{
    private:
        Controller* con;
        lock_distributor lockdistributor;
    public:
        /*CONSTRUCTOR*/
        explicit TUI(Controller* con=new Controller());

        /*GETTERS AND SETTERS*/
        void setController(Controller *c);
        Controller* getController();

        /*VIEW SPECIFIC FUNCTIONS*/
        void printGamefield();
        void endInputThread();
};
#endif
