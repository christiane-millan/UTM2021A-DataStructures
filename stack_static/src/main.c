#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "stack.h"

int menu();

int main(){

    Stack *my_stack = createStack(10);

    return 0;
}

int menu(){
    int option;
    printf("\n\n\n*** MENU PILA***\n");
    printf("\n1. Insertar elemento");
    printf("\n2. Eliminar elemento");
    printf("\n3. Mirar elemento de la cima");
    printf("\n4. Mostrar pila");
    printf("\n5. Salir");
    printf("\nIngrear una opción:");
  
    scanf("%d", &option);
    return option;
}