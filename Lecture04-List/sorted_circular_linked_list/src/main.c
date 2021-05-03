#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "clinkedlist.h"

int menu();

int main(){
    Clinked_list *clinked_list = create_clinked_list();
    int option, item, del_node;

    while(1){
        option = menu();
        switch (option){
        case 1: printf("Ingresar el elemento a insertar:");
                scanf("%d", &item);
                insert(&clinked_list->head, item);
            break;
        case 2: printf("Ingresar el elemento a eliminar:");
                scanf("%d", &item);
                del_node = delete_node(&clinked_list->head, item);
                if( del_node == INT_MIN){
                    printf("Lista vacía (underflow)...");
                } else {
                    if (del_node == INT_MAX){
                        printf("Elemento no fue encontrado...\n");
                    } else {
                        printf("Elemento eliminado correctamente...\n");
                    }
                }
            break;

        case 3: display(clinked_list);
            break;
        case 4: exit(0);
            break;
        default: printf("Opción inválida, intenta de nuevo...");
        }
    }
    return 0;
}

int menu(){
    int option;
    printf("\n\n\n*** MENU LISTA CIRCULAR LIGADA***\n");
    printf("\n1. Insertar elemento");
    printf("\n2. Eliminar elemento ");
    printf("\n3. Mostrar lista");
    printf("\n4. Salir");
    printf("\nIngrear una opción:");
  
    scanf("%d", &option);
    return option;    
}