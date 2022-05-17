#include "tsv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    LL_NODE *q = NULL;

    q = malloc(sizeof(LL_NODE));
 
    tsv_deserialize(q, "database.tsv");
    debug_list(q);
    tsv_serialize(q, "database2.tsv"); 

    return 0;
}

