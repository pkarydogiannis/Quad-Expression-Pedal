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
	
	
	mvprintw(3, PAD, "EXP0: 0");
	attroff(A_REVERSE);	
	
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
			valueUpdate(highlight, TRUE);
			break;
		case 68:
			valueUpdate(highlight, FALSE);
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

void valueUpdate(int highlight, bool direction)
{
	mvprintw(15,PAD,"in valueUpdate()");
	switch(highlight){
		case 0:
			if(direction)
			{
				if(value0<=RESOLUTION) value0++;
			}
			else 
			{
				if (value0>0) value0--;
			}
			mvprintw(3+highlight, PAD, "EXP%d: %d", highlight, value0);
			refresh();
			break;
		case 1:
			if(direction)
			{
				if(value1<=RESOLUTION) value1++;
			}
			else 
			{
				if (value1>0) value1--;
			}
			mvprintw(3+highlight, PAD, "EXP%d: %d", highlight, value1);
			refresh();
			break;
		case 2:
		if(direction)
			{
				if(value2<=RESOLUTION) value2++;
			}
			else 
			{
				if (value2>0) value2--;
			}
			mvprintw(3+highlight, PAD, "EXP%d: %d", highlight, value2);
			refresh();
			break;
		case 3:
		if(direction)
			{
				if(value3<=RESOLUTION) value3++;
			}
			else 
			{
				if (value3>0) value3--;
			}
			mvprintw(3+highlight, PAD, "EXP%d: %d", highlight, value3);
			refresh();
			break;
	}
}