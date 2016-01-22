/**********************
 * game.h
 * DANIEL STONE 2016
 **********************/
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
        void notifyBoard();
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        void setPiece();
        void manPiece(int r, int c, int state);
        bool getIsWon();
        bool goodMove();
        int **theGrid;
    private:
	bool isValidMove;
        bool noMerge;
        bool isWon;
};

#endif
