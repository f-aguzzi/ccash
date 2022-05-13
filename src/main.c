#include "tsv.h"
#include <stdlib.h>
#include <string.h>

int main()
{
    LL_NODE *a, *b, *c, *q;
    
    a = malloc(sizeof(LL_NODE));
    strcpy(a->data.date, "2020-11-12");
    strcpy(a->data.shop, "Negozio1");
    a->data.amount = 123.3;
    strcpy(a->data.cathegory, "Varie");

    b = malloc(sizeof(LL_NODE));
    strcpy(b->data.date, "2021-10-32");
    strcpy(b->data.shop, "Negozio2");
    b->data.amount = 11.32;
    strcpy(b->data.cathegory, "Mangimi");

    c = malloc(sizeof(LL_NODE));
    strcpy(b->data.date, "2021-10-32");
    strcpy(b->data.shop, "Negozio2");
    b->data.amount = 11.32;
    strcpy(b->data.cathegory, "Mangimi");

    
    a->next = b;
    b->next = c;

    tsv_serialize(a, "vitelli.tsv");
    tsv_deserialize(q, "vitelli.tsv");
    
    return 0;
}

