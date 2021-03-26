#ifndef DQUEUE_H
#define DQUEUE_H

struct qnode {
    int data,
    QNode next;
};

struct queue{
    QNode *front, *rear;
};

typedef struct qnode QNode;
typedef struct queue Queue;

Queue* create_queue();
QNode* new_node(int item);
void destroy_queue(QNode *queue);
int is_empty(QNode *queue);
void enqueue(QNode *queue, int item);
int dequeue(QNode *queue);
int peek(QNode *queue);
void display(QNode *queue);

#endif