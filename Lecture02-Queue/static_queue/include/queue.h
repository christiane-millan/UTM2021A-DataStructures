#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

struct queue{
    int front, rear;
    unsigned capacity;
    int *array;
};

Queue* create_queue(unsigned capacity);
void destroy_queue(Queue *queue);
void enqueue(Queue *queue, int item);
int dequeue(Queue *queue);
int peek(Queue *queue);
void display(Queue *queue);

int is_full(Queue *queue);
int is_empty(Queue *queue);
#endif
