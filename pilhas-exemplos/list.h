//
// Created by pedro on 05/04/2021.
//

#ifndef PR5_LIST_H
#define PR5_LIST_H

typedef struct item {
    int key;
} Item;

typedef struct cell {
    Item item;
    struct cell* next;
} Cell;

typedef struct list {
    Cell* head;
    int size;
} List;


/* Start a list */
void ListStart(List *);

/* Return 1 if a list is empty and 0 otherwise */
int ListIsEmpty(List *);

/* Insert an element x in the position p of a list */
void ListInsert(List *, int, Item);

/* Remove an element from the position p of the list and return through the pX parameter
 * the function returns 0 if there is not an element in position p in the list, 1 otherwise */
int ListRemove(List *, int, Item *);

/* return the list size */
int ListSize(List *);

void ListPrint(List *);

void ListTest();

#endif //PR5_LIST_H
