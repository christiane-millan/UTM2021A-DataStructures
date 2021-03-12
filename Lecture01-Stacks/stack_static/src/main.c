#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "stack.h"

int menu();

int main(){

    Stack *my_stack = createStack(10);
    int option, item;

    while(1){
        option = menu();
        switch (option){
        case 1: printf("Ingresar el elemento entero a insertar:");
                scanf("%d", &item);
                push(my_stack, item);
                break;
        case 2: item = pop(my_stack);
                if(item != INT_MIN)
                    printf("Elemento retirado de la pila %d", item);
                break;
        case 3: item = peek(my_stack);
                if(item == INT_MIN)
                    printf("No hay elementos en la pila");
                else
                    printf("ELemento de la cima: %d", item);
                break;
        case 4: display(my_stack);
                break;
        case 5: destroyStack(my_stack);
                exit(EXIT_SUCCESS);
        default:printf("Opción inválida");
                break;
        }    
    }

    return EXIT_SUCCESS;
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