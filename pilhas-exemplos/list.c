//
// Created by pedro on 05/04/2021.
//
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

/* Start a list */
void ListStart(List *list) {
    list->head = (Item*) malloc(sizeof(Item));
    list->head->next = NULL;
    list->size = 0;
}


int ListIsEmpty(List *list) {
    return (list->size == 0);
}

void ListInsert(List *list, int p, Item item) {
    if (p > list->size)
        return;
    Cell* cell = (Cell*) malloc(sizeof(Cell));
    Cell *current = list->head;
    for (int i=0;i<p;i++)
        current = current->next;
    cell->item = item;
    cell->next = current->next;
    current->next = cell;
    list->size++;
}

int ListRemove(List *list, int p, Item *item) {
    if (p > list->size)
        return 0;
    Cell *current = list->head;
    for (int i=0;i<p;i++)
        current = current->next;
    (*item) = current->next->item;
    Cell *removedItem = current->next;
    current->next = current->next->next;
    free(removedItem);
    list->size--;
    return 1;
}

int ListSize(List *list) {
    return list->size;
}

void ListPrint(List * list) {
    printf("[");
    Cell* current = list->head;
    for (int i=0;i<list->size;i++) {
        current = current->next;
        printf("%d ", current->item.key);
    }
    printf("]\n");
}

void ListTest() {
    List list;
    ListStart(&list);

    if (ListIsEmpty(&list) == 1)
        printf("The list is empty.\n");

    Item item;
    item.key = 9;
    printf("List >> "); ListPrint(&list);
    printf("Adding item: %d\t", item.key);
    ListInsert(&list, 0, item);
    printf("List >> "); ListPrint(&list);
    item.key = 8;
    ListInsert(&list, 1, item);
    printf("List >> "); ListPrint(&list);

    Item removedItem;
    if (ListRemove(&list, 1, &removedItem) == 1)
        printf("Removed item: %d\n", removedItem.key);
    else
        printf("Impossible to remove an item!!!\n");
    printf("List >> "); ListPrint(&list);

    item.key = 7;
    ListInsert(&list, 1, item);
    printf("List >> "); ListPrint(&list);

    item.key = 6;
    ListInsert(&list, 1, item);
    printf("List >> "); ListPrint(&list);

    if (ListRemove(&list, 1, &removedItem) == 1)
        printf("Removed item: %d\n", removedItem.key);
    else
        printf("Impossible to remove an item!!!\n");
    printf("List >> "); ListPrint(&list);

    printf("The list size is %d.\n", ListSize(&list));
}