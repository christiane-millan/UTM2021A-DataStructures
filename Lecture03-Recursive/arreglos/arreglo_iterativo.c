#include <stdio.h>

void display_iterative(int num[], int size);
void display_recursive(int num[], int size);

int main(){
    int numbers[] = {1, 2, 3, 4, 5};


    //display_iterative(numbers, 5);
    display_recursive(numbers, 5);

    return 0;
}

void display_iterative(int num[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ",num[i]);
    }
    printf("\n");
}

void display_recursive(int num[], int size){
    if (size != 0){
        display_recursive(num, size -1);
        printf("%d ", num[size - 1]);
    }
}