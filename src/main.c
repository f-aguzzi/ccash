#include "tsv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

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
        /* Title */
        erase();
        attron(A_STANDOUT);
        printw("See checks");
        attroff(A_STANDOUT);

        /* Navigate the list */
        LL_NODE *p = head;
        while (p != NULL)
        {
            printw("\n");
            attron(A_BOLD);
            printw("%s %s\n", p->data.date, p->data.shop);
            attroff(A_BOLD);
            printw("Date: %s\n", p->data.date);
            printw("Product: %s\n", p->data.product_name);
            printw("Shop: %s\n", p->data.shop);
            printw("Price: %s\n", p->data.amount);
            printw("Cathegory: %s\n", p->data.cathegory);

            p = p->next;
        }

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

void main_menu(WINDOW *w)
{
    /* title */
    wattron(w, A_STANDOUT);
    wprintw(w, "CCASH - v0.0.1\n\n");
    wattroff(w, A_STANDOUT);
    wrefresh(w);

    /* Menu */
    wattron(w, A_BOLD);
    wprintw(w, "Menu \n");
    wattroff(w, A_BOLD);

    wprintw(w, "(1) Insert new check\n");
    wprintw(w, "(2) See list of checks\n");

    wrefresh(w);
}

void insert_product(WINDOW *w, LL_NODE *head)
{
    /* Title */
    werase(w);
    wattron(w, A_STANDOUT);
    wprintw(w, "Insert new check\n");
    wattroff(w, A_STANDOUT);

    /* Insert date */
    wprintw(w, "\n Date (YYYY-MM-GG): \n");
    char date_buf[11];
    wscanw(w, "%s", date_buf);

    /* Insert shop */
    wprintw(w, "Name of the shop: \n");
    char shop_buf[50];
    wscanw(w, "%s", shop_buf);

    /* Insert product name */
    wprintw(w, "Name of the product: \n");
    char prod_buf[30];
    wscanw(w, "%s", prod_buf);

    /* Insert amount */
    wprintw(w, "Price paid: \n");
    float price_buf;
    wscanw(w, "%f", &price_buf);

    /* Insert cathegory */
    wprintw(w, "Cathegory: \n");
    char cat_buf[30];
    wscanw(w, "%s", cat_buf);

    /* Create linked list node from buffers and insert */
    Entry e;
    strcpy(e.date, date_buf);
    strcpy(e.shop, shop_buf);
    strcpy(e.product_name, prod_buf);
    e.amount = price_buf;
    strcpy(e.cathegory, cat_buf);

    ins_ordered(e, head);
}
