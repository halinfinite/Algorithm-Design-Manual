#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

LinkedList *create_linked_list();
void insert_at_head(LinkedList* list, int data);
void delete_linked_list(LinkedList* list);
void print_linked_list(const LinkedList *list);

#endif // LINKED_LIST_H