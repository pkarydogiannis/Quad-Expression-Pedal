#include "uihost.h"

void initCurses(void)
{
	WINDOW *w = initscr();
	curs_set(FALSE);
	cbreak();
	noecho();
}

void initUI(void)
{
	attron(A_REVERSE);
	mvprintw(1, BIG_PAD*2, "QUAD EXPRESS HOST");
	attroff(A_REVERSE);	

	mvprintw(3, PAD, "EXP1: 0");
	mvprintw(4, PAD, "EXP2: 0");
	mvprintw(5, PAD, "EXP3: 0");
	mvprintw(6, PAD, "EXP4: 0");
	
	mvprintw(8, PAD,"Press any key to quit.");
}