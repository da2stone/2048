/**********************
 * main.cc
 * DANIEL STONE 2016
 **********************/
#include "game.h"
#include "controller.h"
#include "display.h"
#include "textDisplay.h"
#include <iostream>
using namespace std;

 int main() {
    Controller c;
    cout << "Welcome to 2048" << endl;
    c.play();
 }