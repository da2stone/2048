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
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << game->theGrid[row][col] << " ";
        }
        cout << endl;
    }
}