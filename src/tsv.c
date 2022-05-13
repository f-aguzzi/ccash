#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tsv.h"

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

    /* Deserialization */
    char *line;
    line = malloc(sizeof(char) * 200);
    fscanf(file, "%s", line);

    while (line != NULL)
    {
        /* Create linked list node */
        LL_NODE *node;
        Entry entry;

        /* Eliminate leading whitespace */
        int cursor = 0;
        while ((line[cursor] == ' ' || line[cursor] == '\t') && line[cursor] != '\0')
        {
            cursor++;
        }
        strncpy(line, &line[cursor], 100 - cursor);

        /* Parse the line */
        int section = 0;
        char *token = strtok(line, " \t");
        while (token != NULL)
        {
            if (section == 0)
            {
                strcpy(entry.date, token);
            }
            else if (section == 1)
            {
                strcpy(entry.shop, token);
            }
            else if (section == 2)
            {
                entry.amount = atof(token);
            }
            else if (section == 3)
            {
                strcpy(entry.cathegory, token);
            }
            else
            {
                fprintf(stderr, "Parsing error: invalid schema");
                return 1;
            }
            section++;
            token = strtok(line, " \t");
        }

        int ins = ins_ordered(entry, list);
        if (ins != 0)
        {
            fprintf(stderr, "Error inserting data into list");
            return 1;
        }
        
    }

    free(line);
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

    while (p != NULL)
    {
        char buf[200];

        /* Stringify the struct fields, separate by tab */

        /* Date */
        strcat(buf, p->data.date);
        strcat(buf, "\t");

        /* Shop name */
        strcat(buf, p->data.shop);
        strcat(buf, "\t");

        /* Amount */
        char num_buf[10];
        gcvt(p->data.amount, 9, num_buf);
        strcat(buf, num_buf);
        strcat(buf, "\t");

        /* Cathegory */
        strcat(buf, p->data.cathegory);

        /* Write line to file */
        fprintf(file, "%s", buf);

        /* Move to next node */
        p = p->next;
    }

    fclose(file);
    return 0;
}