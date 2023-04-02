//
// Created by pedro on 05/04/2021.
//

#include <stdio.h>

#include "stack.h"

void StackStart(Stack *stack) {
    ListStart(&stack->list);
}

int StackIsEmpty(Stack *stack) {
    return ListIsEmpty(&stack->list);
}

void StackPush(Stack *stack, Item item) {
    ListInsert(&stack->list, 0, item);
}

int StackPop(Stack *stack, Item *item) {
    return ListRemove(&stack->list, 0, item);
}

int StackSize(Stack *stack) {
    return ListSize(&stack->list);
}

void StackPrint(Stack *stack) {
    ListPrint(&stack->list);
}

void StackTest() {
    Stack stack;
    StackStart(&stack);

    if (StackIsEmpty(&stack) == 1)
        printf("The stack is empty.\n");

    Item item;
    item.key = 0;
    printf("Stack >> "); StackPrint(&stack);
    printf("Stacking item: %d\t", item.key);
    StackPush(&stack, item);
    printf("Stack >> "); StackPrint(&stack);

    item.key = 1;
    StackPush(&stack, item);
    printf("Stacking item: %d\t", item.key);
    printf("Stack >> "); StackPrint(&stack);

    item.key = 2;
    StackPush(&stack, item);
    printf("Stacking item: %d\t", item.key);
    printf("Stack >> "); StackPrint(&stack);

    Item removedItem;
    if (StackPop(&stack, &removedItem) == 1)
        printf("Popped item: %d\n", removedItem.key);
    else
        printf("Impossible to pop an item!!!\n");
    printf("Stack >> "); StackPrint(&stack);

    item.key = 2;
    if (StackPop(&stack, &removedItem) == 1)
        printf("Popped item: %d\n", removedItem.key);
    else
        printf("Impossible to pop an item!!!\n");
    printf("Stack >> "); StackPrint(&stack);

    item.key = 1;
    StackPush(&stack, item);
    printf("Stacking item: %d\t", item.key);
    printf("Stack >> "); StackPrint(&stack);

    StackPop(&stack, &removedItem);
    printf("Popped item: %d\n", removedItem.key);
    printf("Stack >> "); StackPrint(&stack);

    printf("The stack size is %d.\n", StackSize(&stack));
}
