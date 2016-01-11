/*****************************
 * graphicDisplay.h
 * DANIEL STONE 2016
 *****************************/

#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H

#include "window.h"
#include "display.h"

class GraphicDisplay : public Display {
    XWindow *xw;
    
    public:
        GraphicDisplay(Game *g);
        void displayBoard();
};


#endif