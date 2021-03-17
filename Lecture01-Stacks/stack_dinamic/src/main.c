#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stackd.h"

int menu();

int main(){
    Node *top_stack = createStack();
    int option, item;

    while(1){
       option = menu();
       switch (option){
       case 1:  printf("Ingresar el elemento entero a insertar:");
                scanf("%d", &item);
                push(&top_stack, item);
                break;
       case 2:  item = pop(&top_stack);
                if(item != INT_MIN)
                    printf("Elemento eliminado %d", item);
                else    
                    printf("Underflow error");
                break;
        case 3: item = peek(top_stack);
                if(item != INT_MIN)
                    printf("Elemento de la cima: %d", item);
                else
                    printf("No hay elementos en la pila");
                break;
        case 4: display(top_stack);
                break;
        case 5: destroyStack(top_stack);
                exit(EXIT_SUCCESS);
       default: printf("Opción inválida");
                break;
       } 
    }

    return 0;
}

int menu(){
    int option;
    printf("\n\n\n*** MENU PILA DINÁMICA ***\n");
    printf("\n1. Insertar elemento");
    printf("\n2. Eliminar elemento");
    printf("\n3. Mirar elemento de la cima");
    printf("\n4. Mostrar pila");
    printf("\n5. Salir");
    printf("\nIngrear una opción:");
  
    scanf("%d", &option);
    return option;
}