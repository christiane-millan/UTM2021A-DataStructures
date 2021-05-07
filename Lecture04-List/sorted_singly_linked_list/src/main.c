#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "slinkedlist.h"

int menu();

int main(){
    Slinked_list *slinked_list = create_slinked_list();
    int option, item;

    while(1){
        option = menu();
        switch (option){
        case 1: printf("Ingresar el elemento a insertar:");
                scanf("%d", &item);
                insert(&slinked_list->head, item);
            break;
        case 2: printf("Ingresar el elemento a eliminar:");
                scanf("%d", &item); 
                item = delete_node(&slinked_list->head, item);
                if (item == INT_MIN){
                    printf("Lista vacía o el nodo siguiente esta vacio...\n");
                } else {
                    printf("Elemento eliminado: %d", item);
                }
            break;
        case 3: display(slinked_list);
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
    printf("\n\n\n*** MENU LISTA LIGADA***\n");
    printf("\n1. Insertar elemento");
    printf("\n2. Eliminar elemento");
    printf("\n3. Mostrar lista");
    printf("\n4. Salir");
    printf("\nIngrear una opción:");
  
    scanf("%d", &option);
    return option;    
}