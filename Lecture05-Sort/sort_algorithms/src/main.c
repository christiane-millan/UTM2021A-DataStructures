#include <stdio.h>
#include <stdlib.h>
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "bubble_sort.h"
#include "quick_sort.h"
#include "utilities.h"


int main(){
    // 1. Función para generar arreglos de manera aleatoria entre cero y mil
    // (limite_superior +1 - limite_inferior) ;   30 - 50
    //int numero = rand() % 1000; 
    // 2. Menu para elegir el algoritmo
    // 3. Pedir tamaño del arreglo
    // 4. Generar arreglo de aleatorios
    // 5. Mostrar los primeros 10 numeros del arreglo desordenado
    // 6. Ordenar todo el arreglo
    // 7. Mostrar los primeros 10 numero del arreglo ordenado
    // 8. Imprimir el tiempo que tardo en ordenar el arreglo (en segundos).
    int arr[] = {4, 14, 29, 35, 11, 54};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Ordenamiento por selección: \n");
    print_array(arr, size);
    // Hora sistema
    selection_sort(arr, size);
    // Hora sistema
    print_array(arr, size);

    printf("\nOrdenamiento por insercción: \n");
    int arr2[] = {4, 14, 29, 35, 11, 54};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    print_array(arr2, size2);
    insertion_sort(arr2, size2);
    print_array(arr2, size2);

    printf("\nOrdenamiento por mezcla (merge): \n");
    int arr3[] = {40, 10, 86, 44, 93, 26, 69, 17};
    int size3 = sizeof(arr3)/sizeof(arr3[0]);
    print_array(arr3, size3);
    merge_sort(arr3, 0, size3 - 1);
    print_array(arr3, size3);

    printf("\nOrdenamiento por burbuja (bubble \n");
    int arr4[] = {54, 14, 29, 35, 11, 4};
    int size4 = sizeof(arr4)/sizeof(arr4[0]);
    print_array(arr4, size4);
    bubble_sort(arr4, size4);
    print_array(arr4, size4); 

    printf("\nOrdenamiento rápido (quicksort) \n");
    int arr5[] = {54, 14, 29, 35, 11, 4};
    int size5 = sizeof(arr5)/sizeof(arr5[0]);
    print_array(arr5, size5);
    quick_sort(arr5, 0, size5 - 1);
    print_array(arr5, size5); 

    return 0;
}


