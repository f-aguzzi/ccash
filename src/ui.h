#ifndef NCURSES
# define NCURSES
#include <ncurses.h>
#endif

/* linked list header */
#ifndef LL_H
#define LL_H
#include "ll.h"
#endif

void main_menu(WINDOW*);
void insert_product(WINDOW*, LL_NODE*);
void show_list(WINDOW*, LL_NODE*);