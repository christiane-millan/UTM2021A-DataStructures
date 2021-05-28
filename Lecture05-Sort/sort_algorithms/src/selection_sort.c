#include <stdio.h>
#include "selection_sort.h"

void selection_sort(int *arr, int size){
    int pos;
    for (int i = 0; i < size; i++)
    {
        // i = 0, 1, 2 
        pos = min(arr, i, size);
        if ( i != pos) {
            // intercambio de los elementos
            int aux = arr[i];
            arr[i] = arr[pos];
            arr[pos] = aux; 
        }
    }    
}

int min(int *arr, int index, int size){
    int smallest = arr[index];
    int position = index;
    for (int i = index + 1; i < size; i++)
    {
        if(arr[i] < smallest){
            smallest = arr[i];
            position = i;
        }
    }
    return position;
}
