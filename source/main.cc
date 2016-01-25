/**********************************************************
 * main.cc
 * This is where the game comes to life and can be played! 
 * DANIEL STONE 2016
 **********************************************************/
#include "game.h"
#include "controller.h"
#include "boardDisplay.h"
#include "textDisplay.h"
#include "graphicDisplay.h"
#include <iostream>
using namespace std;

 int main() {
    Controller c;
    cout << "Welcome to 2048" << endl;
    c.play();
 }
