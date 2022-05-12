typedef struct Entry {
    char *date;
    char *shop;
    float *amount;
    char *cathegory;
};

typedef struct LL_NODE {
    struct Entry data;
    struct LL_NODE *next;
};

int ins_ordered(struct Entry data, struct LL_NODE *head);