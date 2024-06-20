#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
 
Stack* create_stack() {
    return create_linked_list();
}

void push(Stack *stack, int data) {
    insert_at_head(stack, data);
}

int pop(Stack *stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Error: stack is empty\n");
        return -1;
    }

    Node *top = stack->head;
    int value = top->data;

    stack->head = top->next;
    free(top);

    return value;
}

int stack_peek(const Stack *stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Error: stack is empty\n");
        return -1;
    }

    return stack->head->data;
}

int stack_is_empty(const Stack *stack) {
    return stack->head == NULL;
}