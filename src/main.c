#include "tsv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>


int main()
{
    LL_NODE *q = NULL;

    q = malloc(sizeof(LL_NODE));
 
    tsv_deserialize(q, "database.tsv");
    debug_list(q);
    tsv_serialize(q, "database2.tsv");


    /* ncurses terminal interface */
    initscr();

    /* title */
    attron(A_BOLD);
    printw("CCASH - v0.0.1\n\n");

    refresh();

    /* Menu */
    printw("Menu \n");
    attroff(A_BOLD);

    printw("(1) Insert new check\n");
    printw("(2) See list of checks\n");

    refresh();
    int ch = getch();

    if (ch == '1')
    {
        erase();
        attron(A_BOLD);
        printw("Insert new check");
        attroff(A_BOLD);
    }
    else if (ch == '2')
    {
        erase();
        attron(A_BOLD);
        printw("See checks");
        attroff(A_BOLD);
    }
    else
    {
        erase();
        attron(A_BOLD);
        printw("ERROR");
        attroff(A_BOLD);
    }

    getch();
    endwin();

    return 0;
}

