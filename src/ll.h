typedef struct Entry {
    char date[11];
    char shop[50];
    char product_name[30];
    float amount;
    char cathegory[30];
} Entry;

typedef struct LL_NODE {
    struct Entry data;
    struct LL_NODE *next;
} LL_NODE;

int entrycmp(Entry, Entry);
int ins_ordered(Entry, LL_NODE*);
int del_val(LL_NODE, LL_NODE*);
void debug_list(LL_NODE*);