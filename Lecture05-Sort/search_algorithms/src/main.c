#include <stdio.h>
#include "sequential.h"
#include "binary.h"

int main(){
    int arr[] = {2, 3, 4, 8, 10, 20, 30, 40};

    int item = 10;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Búsqueda secuancial\n");
    int result = sequential_search(arr, size, item);


    if (result == -1)
    {
       printf("El elemento no esta en el arreglo\n"); 
    } else {
        printf("El elemento se encuentra en la posición %d\n", result);
    }

    printf("Busqueda binaria\n");
    int result2 = binary_search(arr, 0, size - 1, item);    

    if (result2 == -1)
    {
       printf("El elemento no esta en el arreglo\n"); 
    } else {
        printf("El elemento se encuentra en la posición %d\n", result);
    }
}
