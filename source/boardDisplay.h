/************************************************************
 * display.h
 * Abstract Display class that allows the board to
 * be shown viusally, through text and graphics
 * DANIEL STONE 2016
 ************************************************************/
#ifndef DISPLAY_H
#define DISPLAY_H

class Game;

class BoardDisplay {
    public:
        BoardDisplay(Game *game);
        virtual ~BoardDisplay() = 0;

        Game *game;
        virtual void displayBoard() = 0;
    private:
};

#endif
