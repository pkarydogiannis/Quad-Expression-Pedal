/*
*	Author: Petros Karydogiannis
*	
*	TODO:
*	•Use an  array for expression values
*	•Map expression input[1] to outputs[4]
*	•Comms
*	•Modularize interface to make it reusable
*	•Makefile
*
*/
#include "header.h"
#include "uihost.h"

int main(int argc, char const *argv[])
{
	int ch;


	initCurses();	
	initUI();
	

	highlight = 0;
	previous = 0;
	value0 = 0;
	value1 = 0;
	value2 = 0;
	value3 = 0;
	do{
		nodelay(stdscr, FALSE);
		ch = getch();
		nodelay(stdscr, TRUE);
		updateUI(ch);	
		
	}while(ch!='q');

	endwin();
	

	return 0;
}