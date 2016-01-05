/*****************************
 * controller.h
 * DANIEL STONE 2016
 *****************************/
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"

class Controller {
    public:
        Controller ();
        ~Controller();
        Game *g;
        void play();
};

#endif