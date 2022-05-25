/* TSV module header */
#ifndef TSV_H
#define TSV_H
#include "tsv.h"
#endif

/* standard IO library */
#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

/* standard library */
#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

/* string library */
#ifndef STRING
#define STRING
#include <string.h>
#endif

/* ncurses library */
#ifndef NCURSES
#define NCURSES
#include <ncurses.h>
#endif

/* ui header */
#ifndef UI_H
#define UI_H
#include "ui.h"
#endif

void main_menu(WINDOW*);
void insert_product(WINDOW*, LL_NODE*);

int main()
{
    LL_NODE *head = NULL;

    head = malloc(sizeof(LL_NODE));
 
    tsv_deserialize(head, "database.tsv");
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