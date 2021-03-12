#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

Stack* createStack(unsigned capacity){
    Stack *stack = (Stack *) malloc (sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *) malloc ( stack->capacity * sizeof(int));
    return stack;
}

void destroyStack(Stack *stack){
    free(stack->array);
    free(stack);
}

void push(Stack *stack, int item){
    if (is_full(stack)){
        printf("\nError de desbordamiento \'overflow\'");
    } else {
        stack->array[++stack->top] = item;
    }
}

int pop(Stack *stack){
    if(is_empty(stack)){
        printf("\nError de desbordamiento \'underflow\'");
        return INT_MIN;
    } else {
        return stack->array[stack->top--];
    }
}

int peek(Stack *stack){
    if (is_empty(stack))
        return INT_MIN;
    return (stack->array[stack->top]);
}

void display(Stack *stack){
    if(is_empty(stack)){
        printf("\n Pila esta vacía, no hay elementos que mostrar.");
    } else {
        for (int i = 0; i < stack->top; i++){
            printf("\n%d", stack->array[i]);
        }
    }
}

int is_full(Stack *stack){
    return stack->top == (int) stack->capacity - 1;
}

int is_empty(Stack *stack){
    return stack->top ==  -1;
}