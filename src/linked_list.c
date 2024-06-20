#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* create_linked_list() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        fprintf(stderr, "Failed to allocate memory for linked list\n");
        return NULL;
    }
    list->head = NULL;
    return list;
}

void insert_at_head(LinkedList *list, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory for new node\n");
        return;
    }
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void delete_linked_list(LinkedList *list) {
    Node *current = list->head;
    Node *next; // allocated on the stack

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

void print_linked_list(const LinkedList *list) {
    const Node *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}