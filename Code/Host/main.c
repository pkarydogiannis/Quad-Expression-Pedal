#include "header.h"


int main(int argc, char const *argv[])
{
	char ch;


	initCurses();	
	initUI();
	ch = getch();
	endwin();
	return 0;
}