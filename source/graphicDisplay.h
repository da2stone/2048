/****************************************************
 * graphicDisplay.h
 * Where the magic of the graphical display is made 
 * DANIEL STONE 2016
 ****************************************************/

#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H

#include "boardDisplay.h"
#include "window.h"

class GraphicDisplay : public BoardDisplay {
    public:
        GraphicDisplay(Game *g);
        ~GraphicDisplay();
        void displayBoard();
    private:
    	Xwindow *xw;
};


#endif
