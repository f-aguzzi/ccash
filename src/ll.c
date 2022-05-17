#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ll.h"

int entrycmp(Entry a, Entry b)
{
    if (
        strcmp(a.date, b.date) == 0 
        && 
        a.amount == b.amount
        &&
        strcmp(a.cathegory, b.cathegory) == 0
        &&
        strcmp(a.shop, b.shop) == 0
    )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int ins_ordered(Entry data, LL_NODE *head)
{
    LL_NODE *t, *p, *prev;

    t = malloc(sizeof(LL_NODE));
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
        /* Already inserted: skip */
        if (entrycmp(t->data, p->data) == 0)
        {
            return 0;
        }
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

int del_val(LL_NODE a, LL_NODE *head)
{
    LL_NODE *p, *q, *prev;
    
    /* Check whether list is empty */
    if (head == NULL)
    {
        fprintf(stderr, "Can't delete: empty list");
    }

    /* Only one element */
    if (entrycmp(head->data, a.data) == 0)
    {
        p = head;
        head = p->next;
        free(p);
        return 0;
    }

    /* More than one element: find the node */
    prev = head;
    p = head->next;
    while (p != NULL)
    {
        if (entrycmp(p->data, a.data) == 0)
        {
            prev->next = p->next;
            free(p);
            return 0;
        }
        p = p->next;
        prev = prev->next;
    }

    return 0;
}

void debug_list(LL_NODE *head)
{
    LL_NODE *cursor = head;
    while (cursor != NULL) {
        printf("%s %s %f %s \n", cursor->data.date, cursor->data.shop, cursor->data.amount, cursor->data.cathegory);
        cursor = cursor->next;
    }
}