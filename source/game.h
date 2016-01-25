/***********************************
 * game.h
 * Where the game logic is produced 
 * DANIEL STONE 2016
 ***********************************/
#ifndef GAME_H
#define GAME_H

#include "boardDisplay.h"
#include "textDisplay.h"
#include "graphicDisplay.h"

class Game {
    public:
        Game();
        ~Game();
        BoardDisplay *board;
        BoardDisplay *board2;

        // Sends a notification to update the status of teh board
        void notifyBoard();

        //Move Methods allow the player to move the tiles to each side of the board
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

        // Strictly for testing specific inputs
        void setPiece();

        // Randomly sets a piece on an empty square on the board 
        void manPiece(int r, int c, int state);

        //Checks if the game is won
        bool getIsWon();

        //Checks if it is a valid move
        bool goodMove();
        int **theGrid;
    private:
	   bool isValidMove;
        bool noMerge;
        bool isWon;
};

#endif
