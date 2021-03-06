/**********************************************
 * textDisplay.cc
 * Magic of the textdisplay occurs here 
 * DANIEL STONE 2016
**********************************************/
#include "textDisplay.h"
#include "game.h"
#include <iostream>
#include <iomanip>
using namespace std;

/**********************
 Constructor/Destructor
************************/

TextDisplay::TextDisplay(Game *g) : BoardDisplay(g) {}

/******************
 Public Methods
*******************/

//displayBoard() Displays the board in text format
void TextDisplay::displayBoard() {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            cout << setw(4) << game->theGrid[row][col] << " ";
        }
        cout << endl;
    }
}
