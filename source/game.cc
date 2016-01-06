/******************************************
 * game.cc
 * This is where the game logic is produced
 * DANIEL STONE 2016
 ******************************************/
 #include "game.h"
 #include "display.h"
 #include <stdlib.h>
 #include <time.h>
 #include <iostream>
 using namespace std;

/************************
 Constructor/Destructor
*************************/

Game::Game() {
    //Initializing the grid
    theGrid = new int*[4];
    for (int i = 0; i < 4; i++) {
        theGrid[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            theGrid[i][j] = 0;
        }
    }
    board = new TextDisplay(this);
    noMerge = false;
}

Game::~Game() {
    for (int i = 0; i < 4; i++) {
        delete [] theGrid[i];
    }
    delete [] theGrid;
    delete board;
}

/***************
 Public Methods
****************/

 void Game::notifyBoard() {
    board->displayBoard();
 }

// Sets a random piece in any open spot on the board
void Game::manPiece(int r, int c, int state) {
    theGrid[r][c] = state;
}

 void Game::setPiece() {
    int row, col, count = 0;
    /*srand (time(NULL));
    do {
        row = rand() % 4 + 0;
        col = rand() % 4 + 0;
        count++;
        if (count >= 15) {
            cout << "Sorry you lose" << endl;
            break;
        }
    } while (theGrid[row][col] != 0);
*/
   // int state = rand() % 2 + 0;
int state = 0;
    if (state == 0) {
        state = 2;
    }
    else if (state == 1) {
        state = 4;
    }
    else {
        state = 8;
    }
//    cout << "Adding " << state << " to [" << row << "," << col << "]" << endl;
    theGrid[0][3] = state;
    count = 0;
 }

// Move operators

 void Game::moveLeft() {
    for (int row = 0; row < 4; row++) {
        int swapCount = 0;
        while (theGrid[row][swapCount] != 0) {
            swapCount++;
            if (swapCount == 3) {
                break;
            }
        }// End while

        if (swapCount > 1) { // Checking for duplicates side by side
            bool first = false;
            int temp, count = 0;;
            for (int i = 0; i < swapCount; i++) {
                if (theGrid[row][i] == theGrid[row][i + 1]) {
                    count++;
                    theGrid[row][i] *=2;
                    theGrid[row][i+1] = 0;
                    cout << "[" << row << "," << i << "] = " << theGrid[row][i] << endl;
                    if (first) {
                        continue;
                    }
                    else {
                        first = true;
                        temp = i + 1;
                    }
                }
            }
            if (count == 2) {
                noMerge = true;
            }
            if (first) {
                swapCount = temp;
            }
        }

        int index = swapCount + 1;

        while (index < 4) {
            if (theGrid[row][index] == 0) {
                index++;
                continue;
            }
            int temp = theGrid[row][swapCount];
            theGrid[row][swapCount] = theGrid[row][index];
            theGrid[row][index] = temp;
            if (swapCount > 0) {
                if (theGrid[row][swapCount - 1] == theGrid[row][swapCount] && !noMerge) {
                    theGrid[row][swapCount - 1] *= 2;
                    theGrid[row][swapCount] = 0;
                    index = swapCount + 1;
                    continue;
                }
            }
            index++;
            swapCount++;
        } //End while (index < 4)
        noMerge = false;
    }  
 }

 void Game::moveRight() {
    for (int row = 0; row < 4; row++) {
        int swapCount = 3;
        while (theGrid[row][swapCount] != 0) {
            swapCount--;
            if (swapCount == 0) {
                break;
            }
        }
        if (swapCount == 0) {
            continue;
        }
        else {
            int index = swapCount - 1;
            while (index >= 0) {
                if (theGrid[row][index] == 0) {
                    index--;
                    continue;
                }
                int temp = theGrid[row][swapCount];
                theGrid[row][swapCount] = theGrid[row][index];
                theGrid[row][index] = temp;
                index--;
                swapCount--;
            }
        }
    }  
}

 void Game::moveUp() {
    for (int col = 0; col < 4; col++) {
        int swapCount = 0;
        while (theGrid[swapCount][col] != 0) {
            swapCount++;
            if (swapCount == 3) {
                break;
            }
        }
        if (swapCount == 3) {
            continue;
        }
        else {
            int index = swapCount + 1;
            while (index < 4) {
                if (theGrid[index][col] == 0) {
                    index++;
                    continue;
                }
                int temp = theGrid[swapCount][col];
                theGrid[swapCount][col] = theGrid[index][col];
                theGrid[index][col] = temp;
                index++;
                swapCount++;
            }
        }
    }
 }

 void Game::moveDown() {
    for (int col = 0; col < 4; col++) {
        int swapCount = 3;
        while (theGrid[swapCount][col] != 0) {
            swapCount--;
            if (swapCount == 0) {
                break;
            }
        }
        if (swapCount == 0) {
            continue;
        }
        else {
            int index = swapCount - 1;
            while (index >= 0) {
                if (theGrid[index][col] == 0) {
                    index--;
                    continue;
                }
                int temp = theGrid[swapCount][col];
                theGrid[swapCount][col] = theGrid[index][col];
                theGrid[index][col] = temp;
                index--;
                swapCount--;
            }
        } 
    }
 }