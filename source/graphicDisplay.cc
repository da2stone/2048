/****************************
 * graphicDisplay.cc
 * DANIEL STONE 2016
 ****************************/

 #include "graphicDisplay.h"
 #include "game.h"
using namespace std;

/*************************
 Constructors/Destructors
 *************************/

 GraphicDisplay::GraphicDisplay(Game *g) : BoardDisplay(g) {
 	xw = new Xwindow();

 	for (int row = 0; row < 4; row++) {
 		for (int col = 0; col < 4; col++) {
 			xw->fillRectangle(row*50+50, col*50+50, 50, 50, 1);
 		}
 	}
 }

 GraphicDisplay::~GraphicDisplay() {
 	delete xw;
 }

 void GraphicDisplay::displayBoard() {
 	for (int row = 0; row < 4; row++) {
 		for (int col = 0; col < 4; col++) {
 			int temp = game->theGrid[col][row];
 			switch(temp) {
 				case 0: 
 				    xw->fillRectangle(row*50+50, col*50+50, 50, 50, 1);
break;
 				case 2:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 2);
break; 
				case 4:
 				    xw->fillRectangle(row*50+50, col*50+50, 50, 50, 2);
break; 
				case 8:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 8);
break; 
				case 16:
 				    xw->fillRectangle(row*50+50, col*50+50, 50, 50, 8);
break; 
				case 32:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 6);
break; 
				case 64:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 6);
break; 
				case 128:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 5);
break; 
				case 256:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 5);
break; 
				case 512:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 4);
break; 
				case 1024:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 4);
break; 
				case 2048:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 3);
 				default:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 1);
 					break;
 			}
 		}
 	}
 }
