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
 void Game::setPiece() {
    int row, col, count = 0;
    srand (time(NULL));
    do {
        row = rand() % 4 + 0;
        col = rand() % 4 + 0;
        count++;
        if (count >= 15) {
            cout << "Sorry you lose" << endl;
            break;
        }
    } while (theGrid[row][col] != 0);

    int state = rand() % 2 + 0;

    if (state == 0) {
        state = 2;
    }
    else if (state == 1) {
        state = 4;
    }
    else {
        state = 8;
    }
    theGrid[row][col] = state;
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
        }
        if (swapCount == 3) {
            continue;
        }
        else {
            int index = swapCount + 1;
            while (index < 4) {
                if (theGrid[row][index] == 0) {
                    index++;
                    continue;
                }
                int temp = theGrid[row][swapCount];
                theGrid[row][swapCount] = theGrid[row][index];
                theGrid[row][index] = temp;
                index++;
                swapCount++;
            }
        }
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