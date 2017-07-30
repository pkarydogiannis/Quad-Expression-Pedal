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

	mvprintw(3, PAD, "EXP0: 0");
	mvprintw(4, PAD, "EXP1: 0");
	mvprintw(5, PAD, "EXP2: 0");
	mvprintw(6, PAD, "EXP3: 0");
	
	mvprintw(8, PAD,"Press any key to quit.");
}

void updateUI(int ch)
{
	int tmp;
	tmp = previous;

	switch(ch){
		case 65:
			
			if (highlight > 0) 
				highlight--;
			else
				highlight = 0; 
			break;
		case 66:
			
			if (highlight < 3) 
				highlight++;
			else 
				highlight = 3;
			break;
		case 67:
			break;
		case 68:
			break;
	}

	attron(A_REVERSE);
	mvprintw(3+highlight, PAD, "EXP%d: 0", highlight);
	attroff(A_REVERSE);
	if (highlight!=previous) 
		mvprintw(3+previous, PAD, "EXP%d: 0", previous);
	

	mvprintw(12, PAD, "%d",ch);
	mvprintw(10, PAD, "highlight:%d", highlight);
	mvprintw(11, PAD, "previous:%d", previous);

	previous = highlight;
	refresh();
	
}