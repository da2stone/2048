/************************
 * textDisplay.cc
 * DANIEL STONE 2016
*************************/
#include "textDisplay.h"
#include "game.h"
#include <iostream>
using namespace std;

/**********************
 Constructor/Destructor
************************/

TextDisplay::TextDisplay(Game *g) : Display(g) {}

/******************
 Public Methods
*******************/

void TextDisplay::displayBoard() {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            cout << game->theGrid[row][col] << " ";
        }
        cout << endl;
    }
}