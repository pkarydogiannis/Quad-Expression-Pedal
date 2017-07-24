/*
	Author: Petros Karydogiannis pk8g15@soton.ac.uk
*/
#ifndef _UIHOST_H
#define _UIHOST_H
#include <ncurses.h>

#define SMALL_PAD 	4	//
#define PAD 		8	//ncurses pads
#define BIG_PAD 	16	//

void initCurses(void);
void initUI(void);

#endif