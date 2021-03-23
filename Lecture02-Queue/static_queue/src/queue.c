#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "queue.h"

Queue* create_queue(unsigned capacity){
    Queue *queue = (Queue *) malloc (sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int *) malloc ( queue->capacity * sizeof(int));
    return queue;
}

void destroy_queue(Queue *queue){
    free(queue->array);
    free(queue);
}

void enqueue(Queue *queue, int item){
    if(is_full(queue))
        printf("Overflow error...");
    else 
        queue->array[++queue->rear] = item;
}

int dequeue(Queue *queue){
    if(is_empty(queue)){
        printf("Underflow error...");
        return INT_MIN;
    } else {
        return queue->array[++queue->front];
    }
}


int peek(Queue *queue){
    if(is_empty(queue)){
        printf("Underflow error...");
        return INT_MIN;
    } else {
        return queue->array[queue->front + 1];
    }
}

void display(Queue *queue){
    if(is_empty(queue)){
        printf("\nCola esta vacía, no hay elementos que mostrar");
    } else {
        for (int i = queue->front + 1; i <= queue->rear; i++){
            printf("\n%d", queue->array[i]);
        }
        
    }
}

int is_full(Queue *queue){
    return (queue->rear == (int) queue->capacity - 1);
}

int is_empty(Queue *queue){
    return (queue->rear == -1);
}