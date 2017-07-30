/*
	Author: Petros Karydogiannis pk8g15@soton.ac.uk
*/
#ifndef _UIHOST_H
#define _UIHOST_H
#include "header.h"


#define SMALL_PAD 	4	//
#define PAD 		8	//ncurses pads
#define BIG_PAD 	16	//

//Menu Variables
int highlight;
int previous;
//Interface Functions
void initCurses(void);
void initUI(void);
void updateUI(int ch);

#endif