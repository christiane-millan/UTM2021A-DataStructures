#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

struct stack{
    int top;
    unsigned capacity;
    int *array;
};

Stack* createStack(unsigned capacity);
void destroyStack(Stack *stack);
void push(Stack *stack, int item);
int pop(Stack *stack);
int peek(Stack *stack);
void display(Stack *stack);
int is_full(Stack *stack);
int is_empty(Stack *stack);
#endif