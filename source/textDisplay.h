/***********************
 * textDisplay.h
 * DANIEL STONE 2016
 ***********************/
#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "display.h"

class TextDisplay : public Display {
    public: 
        TextDisplay(Game *g);
        void displayBoard();
};

#endif