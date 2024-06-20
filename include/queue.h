#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

Queue* create_queue();
void enqueue(Queue *queue, int data);
int dequeue(Queue *queue);
int queue_peek(const Queue *queue);
int queue_is_empty(const Queue *queue);

#endif // QUEUE_H