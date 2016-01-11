/*****************************
 * graphicDisplay.h
 * DANIEL STONE 2016
 *****************************/

#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H

#include "boardDisplay.h"
#include "window.h"

class GraphicDisplay : public BoardDisplay {
    Xwindow *xw;
    
    public:
        GraphicDisplay(Game *g);
        ~GraphicDisplay();
        void displayBoard();
};


#endif
