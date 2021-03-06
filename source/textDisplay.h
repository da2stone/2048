/*******************************************
 * textDisplay.h
 * Magic of the text display occurs here
 * DANIEL STONE 2016
 ********************************************/
#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "boardDisplay.h"

class TextDisplay : public BoardDisplay {
    public: 
        TextDisplay(Game *g);
        void displayBoard();
};

#endif
