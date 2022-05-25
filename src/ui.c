/* string library */
#ifndef STRING
#define STRING
#include <string.h>
#endif

/* linked list header */
#ifndef LL_H
#define LL_H
#include "ll.h"
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

void show_list(WINDOW* w, LL_NODE* head)
{
    /* Title */
    werase(w);
    
    wattron(w, A_STANDOUT);
    wprintw(w, "See checks");
    wattroff(w, A_STANDOUT);
    
    /* Navigate the list */
    LL_NODE *p = head;
    
    while (p != NULL)
    {
        wprintw(w, "\n");
        wattron(w, A_BOLD);
        wprintw(w, "%s %s\n", p->data.date, p->data.shop);
        wattroff(w, A_BOLD);
        wprintw(w, "Date: %s\n", p->data.date);
        wprintw(w, "Product: %s\n", p->data.product_name);
        wprintw(w, "Shop: %s\n", p->data.shop);
        wprintw(w, "Price: %f\n", p->data.amount);
        wprintw(w, "Cathegory: %s\n", p->data.cathegory);
        p = p->next;
    }


}

