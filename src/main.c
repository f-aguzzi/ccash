#include "tsv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

int main()
{
    LL_NODE *head = NULL;

    head = malloc(sizeof(LL_NODE));
 
    tsv_deserialize(head, "database.tsv");
    debug_list(head);
    tsv_serialize(head, "database2.tsv");


    /* ncurses terminal interface */
    initscr();

    /* title */
    attron(A_STANDOUT);
    printw("CCASH - v0.0.1\n\n");
    attroff(A_STANDOUT);
    refresh();

    /* Menu */
    attron(A_BOLD);
    printw("Menu \n");
    attroff(A_BOLD);

    printw("(1) Insert new check\n");
    printw("(2) See list of checks\n");

    refresh();
    int ch = getch();

    /* Insert new check */
    if (ch == '1')
    {
        /* Title */
        erase();
        attron(A_STANDOUT);
        printw("Insert new check\n");
        attroff(A_STANDOUT);

        /* Insert date */
        printw("\n Date (YYYY-MM-GG): \n");
        char date_buf[11];
        scanw("%s", date_buf);

        /* Insert shop */
        printw("Name of the shop: \n");
        char shop_buf[50];
        scanw("%s", shop_buf);

        /* Insert product name */
        printw("Name of the product: \n");
        char prod_buf[30];
        scanw("%s", prod_buf);

        /* Insert amount */
        printw("Price paid: \n");
        float price_buf;
        scanw("%f", &price_buf);

        /* Insert cathegory */
        printw("Cathegory: \n");
        char cat_buf[30];
        scanw("%s", cat_buf);

        /* Create linked list node from buffers and insert */
        Entry e;
        strcpy(e.date, date_buf);
        strcpy(e.shop, shop_buf);
        strcpy(e.product_name, prod_buf);
        e.amount = price_buf;
        strcpy(e.cathegory, cat_buf);

        ins_ordered(e, head);
        
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
