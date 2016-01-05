/*********************************
 * game.cc
 * DANIEL STONE 2016
 *********************************/
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

 void Game::setPiece() {
    int row, col;
    srand (time(NULL));
    do {
        row = rand() % 3 + 0;
        col = rand() % 3 + 0;
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
 }

 void Game::moveLeft() {
    for (int row = 0; row < 4; row++) {
        int swapCount = 0;
        while (theGrid[row][swapCount] != 0) {
            swapCount++;
            if (swapCount == 4) {
                break;
            }
        }
        if (swapCount == 4) {
            continue;
        }
        else {
            while (swapCount < 3) {
                int temp = theGrid[row][swapCount + 1];
                if (temp == theGrid[row][swapCount]) {
                    temp *= 2;
                }
                theGrid[row][swapCount] = temp;
                swapCount++;
            }
            theGrid[row][swapCount] = 0;
        }
    }
    
 }

 void Game::moveRight() {
for (int row = 0; row < 4; row++) {
        int swapCount = 3;
        while (theGrid[row][swapCount] != 0) {
            swapCount--;
            if (swapCount == -1) {
                break;
            }
        }
        if (swapCount == -1) {
            continue;
        }
        else {
            while (swapCount > 0) {
                int temp = theGrid[row][swapCount - 1];
                if (temp == theGrid[row][swapCount]) {
                    temp *= 2;
                }
                theGrid[row][swapCount] = temp;
                swapCount++;
            }
            theGrid[row][swapCount] = 0;
        }
    } 
    
}

 void Game::moveUp() {
for (int col = 0; col < 4; col++) {
        int swapCount = 0;
        while (theGrid[swapCount][col] != 0) {
            swapCount++;
            if (swapCount == 4) {
                break;
            }
        }
        if (swapCount == 4) {
            continue;
        }
        else {
            while (swapCount < 3) {
                int temp = theGrid[swapCount + 1][col];
                if (temp == theGrid[swapCount][col]) {
                    temp *= 2;
                }
                theGrid[swapCount][col] = temp;
                swapCount++;
            }
            theGrid[swapCount][col] = 0;
        }
    }
    
 }

 void Game::moveDown() {
for (int col = 0; col < 4; col++) {
        int swapCount = 3;
        while (theGrid[swapCount][col] != 0) {
            swapCount--;
            if (swapCount == -1) {
                break;
            }
        }
        if (swapCount == -1) {
            continue;
        }
        else {
            while (swapCount > 0) {
                int temp = theGrid[swapCount - 1][col];
                if (temp == theGrid[swapCount][col]) {
                    temp *= 2;
                }
                theGrid[swapCount][col] = temp;
                swapCount++;
            }
            theGrid[swapCount][col] = 0;
        }
    } 
    
 }