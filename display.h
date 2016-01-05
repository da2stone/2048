/***********************
 * display.h
 * DANIEL STONE 2016
 ***********************/
#ifndef DISPLAY_H
#define DISPLAY_H

class Game;

class Display {
    public:
        Display(Game *game);
        virtual ~Display() = 0;

        Game *game;
        virtual void displayBoard() = 0;
    private:
};

#endif