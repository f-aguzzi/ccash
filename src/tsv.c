/* string library */
#ifndef STRING
#define STRING
#include <string.h>
#endif

/* standard IO library */
#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

/* standard library */
#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

/* tsv header file */
#ifndef TSV_H
#define TSV_H
#include "tsv.h"
#endif

int tsv_deserialize(LL_NODE *list, char *filename)
{
    FILE *file;

    /* Open database file */
    file = fopen(filename, "r");

    /* File not found */
    if (file == NULL)
    {
        fprintf(stderr, "Database not found.");
        return 0;
    }

    /* Check if schema is correct */
    char schema[50];
    fgets(schema, 50, file);
    if (strcmp(schema, "Date\tShop\tProduct name\tAmount\tCathegory\n") != 0)
    {
        printf("%s", schema);
        fprintf(stderr, "Can't read file: wrong schema");
        return 0;
    }

    /* Deserialization */
    char date[50];
    char shop[50];
    char product_name[30];
    char amount[50];
    char cathegory[50];

    int fileread = fscanf(file, "%s\t%s\t%s\t%s\t%s", date, shop, product_name, amount, cathegory);

    while (fileread != EOF)
    {
        /* Create linked list node */
        LL_NODE *node;
        Entry entry;

        /* Convert the line */
        strcpy(entry.date, date);
        strcpy(entry.shop, shop);
        strcpy(entry.product_name, product_name);
        gcvt(entry.amount, 50, amount);
        strcpy(entry.cathegory, cathegory);
        

        /* Insert the node in time order */
        int ins = ins_ordered(entry, list);
        if (ins != 0)
        {
            fprintf(stderr, "Error inserting data into list");
            return 1;
        }

        /* Move to next line */
        fileread = fscanf(file, "%s\t%s\t%s\t%s\t%s", date, shop, product_name, amount, cathegory);
        
    }

    /* Close the file and return */
    fclose(file);
    return 0;
}


int tsv_serialize(LL_NODE *head, char *filename)
{
    FILE *file;
    file = fopen(filename, "w");

    if (file == NULL)
    {
        fprintf(stderr, "Error opening file. Can't write.");
        return 1;
    }

    LL_NODE *p = head;

    /* Write heading */
    fprintf(file, "%s", "Date\tShop\tProduct name\tAmount\tCathegory\n");

    while (p != NULL)
    {
        char buf[200];
        buf[0] = '\0';

        /* Stringify the struct fields, separate by tab */

        /* Date */
        strcat(buf, p->data.date);
        strcat(buf, "\t");

        /* Shop name */
        strcat(buf, p->data.shop);
        strcat(buf, "\t");

        /* Product name */
        strcat(buf, p->data.product_name);
        strcat(buf, "\t");

        /* Amount */
        char num_buf[20];
        sprintf(num_buf,"%f", p->data.amount);
        strcat(buf, num_buf);
        strcat(buf, "\t");

        /* Cathegory */
        strcat(buf, p->data.cathegory);

        /* If it's not the last line, add a line feed */
        if (p->next != NULL) {
            strcat(buf, "\n");
        }

        /* Write line to file */
        fprintf(file, "%s", buf);

        /* Move to next node */
        p = p->next;
    }

    fclose(file);
    return 0;
}