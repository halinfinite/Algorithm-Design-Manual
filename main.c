#include "all_headers.h"
#include <stdio.h>

int main() {
    LinkedList *list = create_linked_list();
    if (list == NULL) {
        return 1; // Exit if list creation failed
    }

    insert_at_head(list, 10);
    insert_at_head(list, 20);
    insert_at_head(list, 30);

    print_linked_list(list);
    delete_linked_list(list);

    Stack* stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", stack_peek(stack)); // Should print 30

    printf("Popped element: %d\n", pop(stack)); // Should print 30
    printf("Popped element: %d\n", pop(stack)); // Should print 20

    printf("Is stack empty? %d\n", stack_is_empty(stack)); // Should print 0 (false)

    printf("Popped element: %d\n", pop(stack)); // Should print 10
    printf("Is stack empty? %d\n", stack_is_empty(stack)); // Should print 1 (true)

    // Try popping from empty stack
    printf("Popped element: %d\n", pop(stack)); // Should print error message and -1
    
    Queue *queue = create_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Peek: %d\n", queue_peek(queue)); // Should print 10

    printf("Dequeue: %d\n", dequeue(queue)); // Should print 10
    printf("Dequeue: %d\n", dequeue(queue)); // Should print 20
    printf("Dequeue: %d\n", dequeue(queue)); // Should print 30

    if (queue_is_empty(queue)) {
        printf("Queue is empty\n"); // Should print this
    }

    return 0;
}