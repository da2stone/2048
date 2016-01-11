/****************************
 * graphicDisplay.cc
 * DANIEL STONE 2016
 ****************************/

 #include "graphicDisplay.h"

/*************************
 Constructors/Destructors
 *************************/

 GraphicDisplay::GraphicDisplay(Game *g) : Display(g) {
 	xw = new XWindow();

 	for (int row = 0; row < 4; row++) {
 		for (int col = 0; col < 4; col++) {
 			xw->fillRectangle(row*50+50, col*50+50, 50, 50, 1)
 		}
 	}
 }

 GraphicDisplay::~GraphicDisplay() {
 	delete xw;
 }

 void GraphicDisplay::displayBoard() {
 	for (int row = 0; row < 4; row++) {
 		for (int col = 0; col < 4; col++) {
 			int temp = theGrid[row][col];
 			switch(temp) {
 				case 0: 
 				    xw->fillRectangle(row*50+50, col*50+50, 50, 50, 1);
 				case 2:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 1);
 				case 4:
 				    xw->fillRectangle(row*50+50, col*50+50, 50, 50, 2);
 				case 8:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 2);
 				case 16:
 				    xw->fillRectangle(row*50+50, col*50+50, 50, 50, 8);
 				case 32:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 8);
 				case 64:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 6);
 				case 128:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 6);
 				case 256:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 5);
 				case 512:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 5);
 				case 1024:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 4);
 				case 2048:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 3);
 				default:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 1);
 					break;
 			}
 		}
 	}
 }