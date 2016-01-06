/**********************
 * game.h
 * DANIEL STONE 2016
 **********************/
#ifndef GAME_H
#define GAME_H

#include "display.h"
#include "textDisplay.h"

class Game {
    public:
        Game();
        ~Game();
        Display *board;
        void notifyBoard();
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        void setPiece();
        void manPiece(int r, int c, int state);
        int **theGrid;
    private:
        bool noMerge;
};

#endif