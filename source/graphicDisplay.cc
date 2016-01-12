/****************************
 * graphicDisplay.cc
 * DANIEL STONE 2016
 ****************************/

 #include "graphicDisplay.h"
 #include "game.h"
 #include <sstream>
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
xw->drawString(row*50+75, col*50+75, "2", 0);
break; 
				case 4:
 				    xw->fillRectangle(row*50+50, col*50+50, 50, 50, 2);
xw->drawString(row*50+75, col*50+75, "4", 0);
break; 
				case 8:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 8);
xw->drawString(row*50+75, col*50+75, "8", 0);
break; 
				case 16:
 				    xw->fillRectangle(row*50+50, col*50+50, 50, 50, 8);
xw->drawString(row*50+75, col*50+75, "16", 0);
break; 
				case 32:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 6);
xw->drawString(row*50+75, col*50+75, "32", 1);
break; 
				case 64:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 6);
xw->drawString(row*50+75, col*50+75, "64", 1);
break; 
				case 128:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 5);
xw->drawString(row*50+55, col*50+75, "128", 1);
break; 
				case 256:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 5);
xw->drawString(row*50+55, col*50+75, "256", 1);
break; 
				case 512:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 4);
xw->drawString(row*50+55, col*50+75, "512", 0);
break; 
				case 1024:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 4);
xw->drawString(row*50+50, col*50+75, "1024", 0);
break; 
				case 2048:
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 3);
xw->drawString(row*50+50, col*50+75, "2048", 1);
break;
 				default:
					ostringstream iss;
					iss << temp;
					string numStr;
					numStr = iss.str();
 					xw->fillRectangle(row*50+50, col*50+50, 50, 50, 3);
xw->drawString(row*50+50, col*50+75, numStr, 1);
 					break;
 			}
 		}
 	}
 }
