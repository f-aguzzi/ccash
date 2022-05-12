#include <stdlib.h>
#include <stdio.h>
#include "ll.h"

int ins_ordered(struct Entry data, struct LL_NODE *head)
{
    struct LL_NODE *t, *p, *prev;

    t = malloc(sizeof(struct LL_NODE));
    if (t == NULL)
    {
        fprintf(stderr, "Memory allocation error");
    }
    
    t->data = data;

    /* Empty list: append on the head */
    if (head == NULL)
    {
        head = t;
        t->next = NULL;
        return 0;
    }

    /* Non-empty list: compare with head */
    if (strcmp(data.date, head->data.date) == 0)
    {
        free(t);
        return 0;
    }

    /* Change the head */
    if (strcmp(data.date, head->data.date) < 0)
    {
        t->next = head;
        head = t;
        return 0;
    }

    /* List with only one element */
    if (head->next == NULL)
    {
        head->next = t;
        t->next = NULL;
        return 0;
    }

    /* List with more than one element */
    prev = head;
    p = head->next;
    while (p != NULL)
    {
        /* Can insert here */
        if (strcmp(data.date, p->data.date) < 0)
        {
            t->next = p;
            prev->next = t;
            return 0;
        }
        p = p->next;
        prev = prev->next;
    }

    prev->next = t;
    t->next = NULL;
    return 0;

}