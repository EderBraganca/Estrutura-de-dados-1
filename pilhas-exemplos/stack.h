//
// Created by pedro on 05/04/2021.
//

#ifndef PR5_STACK_H
#define PR5_STACK_H

#include "list.h"

typedef struct stack {
    List list;
} Stack;

/* Starts a stack */
void StackStart(Stack *);

/* Return 1 if the stack is empty, 0 otherwise */
int StackIsEmpty(Stack *);

/* Insert an item in top of the stack */
void StackPush(Stack *, Item);

/* Remove an item from the top of the stack and return through the parameter
 * the function returns 0 if there is not element of the stack, 1 otherwise */
int StackPop(Stack *, Item *);

/* Return the stack size */
int StackSize(Stack *);

void StackPrint(Stack *);

void StackTest();

#endif //PR5_STACK_H
