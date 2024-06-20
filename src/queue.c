#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue* create_queue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue *queue, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (queue_is_empty(queue)){
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

int dequeue(Queue *queue) {
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Error: Queue is empty\n");
        return -1;
    }

    Node *temp = queue->head;
    int data = temp->data;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(temp);
    return data;
}

int queue_peek(const Queue *queue) {
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Error: Queue is empty\n");
        return -1;
    }
    return queue->head->data;
}

int queue_is_empty(const Queue* queue) {
    return (queue->head == NULL);
}
