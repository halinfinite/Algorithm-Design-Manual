#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

typedef LinkedList Stack;

Stack* create_stack();
void push(Stack *stack, int data);
int pop(Stack *stack);
int stack_peek(const Stack *stack);
int stack_is_empty(const Stack *stack);

#endif // STACK_H