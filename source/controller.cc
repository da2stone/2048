/*********************************************************
 * controller.cc
 * Concrete controller that allows the player to make 
 * moves and interact with the board, to play the game
 * DANIEL STONE 2016
 *********************************************************/
 #include "controller.h"
 #include <iostream>
 using namespace std;

/************************
 Constructor/Destructor
*************************/

Controller::Controller() {} 
Controller::~Controller() {}

/******************
 Public Methods
*******************/

 void Controller::play() {
    bool isWon = false;
    bool addNumber = true;
    Game *g = new Game();
    while(!isWon) { 
        if (g->getIsWon()) {
            isWon = true;
            break;
        } 
        if (addNumber) {
            g->setPiece();
        }
        g->notifyBoard();

        cout << "Which direction would you like to go <Left, Right, Up, Down>" << endl;
        string opt;
        cin >> opt;
        if (opt == "Left") {
            g->moveLeft();
            addNumber = g->goodMove();
        }
        else if (opt == "Right") {
            g->moveRight();
            addNumber = g->goodMove();
        }
        else if (opt == "Up") {
            g->moveUp();
            addNumber = g->goodMove();
        }
        else if (opt == "Down") {
            g->moveDown();
            addNumber = g->goodMove();
        }
        else if (opt == "Set") {
            int r, c, s;
            cin >> r >> c >> s;
            g->manPiece(r,c,s);
        }
        else {
            cout << "Oops please try again" << endl;
            addNumber = false;
            continue;
        }
    }

    cout << "**** Congrats on winning the game :) *****" << endl;
 }

