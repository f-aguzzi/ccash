#include "tsv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "ui.h"

void main_menu(WINDOW*);
void insert_product(WINDOW*, LL_NODE*);

int main()
{
    LL_NODE *head = NULL;

    head = malloc(sizeof(LL_NODE));
 
    tsv_deserialize(head, "database.tsv");
    debug_list(head);
    tsv_serialize(head, "database2.tsv");


    /* ncurses terminal interface */
    WINDOW *w = initscr();

    main_menu(w);
    int ch = getch();

    /* Insert new check */
    if (ch == '1')
    {
        insert_product(w, head);
    }
    /* See list of previously inserted checks */
    else if (ch == '2')
    {
        show_list(w, head);
    }
    /* Error message */
    else
    {
        erase();
        attron(A_BOLD);
        printw("ERROR\n");
        attroff(A_BOLD);

        printw("Press any key to exit...");
    }

    getch();
    endwin();

    tsv_serialize(head, "database3.tsv");

    return 0;
}