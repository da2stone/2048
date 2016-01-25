/**************************************************
 * display.cc
 * Abstract Display class that allows the board to
 * be shown viusally, through text and graphics
 * DANIEL STONE 2016
 **************************************************/
 #include "boardDisplay.h"
 
/*************************
 Constructor/Destructor
************************/
BoardDisplay::BoardDisplay(Game *g) : game(g) {}
BoardDisplay::~BoardDisplay() {} 
