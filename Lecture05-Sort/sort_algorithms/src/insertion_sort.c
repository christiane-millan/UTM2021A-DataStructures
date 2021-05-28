#include "insertion_sort.h"

void insertion_sort(int *arr, int size){
    int position, j;
    for (int i = 1; i < size; i++)
    {
        position = *(arr + i);
        j = i - 1;
        while( (position <= *(arr + j)) && (j >= 0) ){
            *(arr + (j + 1)) = *(arr + j);
            j = j - 1;
        }
        *(arr + (j + 1)) = position;
    }
}