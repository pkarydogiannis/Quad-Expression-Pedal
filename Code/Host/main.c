#include "header.h"
#include "uihost.h"

int main(int argc, char const *argv[])
{
	int ch;


	initCurses();	
	initUI();
	

	highlight = 0;
	previous = 0;
	do{
		nodelay(stdscr, FALSE);
		ch = getch();
		nodelay(stdscr, TRUE);
		updateUI(ch);	
		
	}while(ch!='q');

	endwin();
	

	return 0;
}