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
                insert_head(&slinked_list->head, item);
            break;
        case 2: printf("Ingresar el elemento a insertar:");
                scanf("%d", &item);
                insert_end(&slinked_list->head, item);
            break;
        case 3: printf("Ingresar el elemento a insertar:");
                scanf("%d", &item);
                insert_after(&slinked_list->head, item);
            break;
        case 4: item = delete_head(&slinked_list->head);
                if (item == INT_MIN){
                    printf("Lista vacía...\n");
                } else {
                    printf("Elemento eliminado (head) %d", item);
                }
            break;
        case 5: item = delete_after(&slinked_list->head);
                if (item == INT_MIN){
                    printf("Lista vacía o el nodo siguiente esta vacio...\n");
                } else {
                    printf("Elemento eliminado (después head) %d", item);
                }
            break;
        case 6: display(slinked_list);
            break;
        case 7: exit(0);
            break;
        default: printf("Opción inválida, intenta de nuevo...");
        }
    }
    return 0;
}

int menu(){
    int option;
    printf("\n\n\n*** MENU LISTA LIGADA***\n");
    printf("\n1. Insertar elemento al inicio (head)");
    printf("\n2. Insertar elemento al final");
    printf("\n3. Insertar elemento intermedio");
    printf("\n4. Eliminar elemento al inicio (head)");
    printf("\n5. Eliminar elemento intermedio");
    printf("\n6. Mostrar lista");
    printf("\n7. Salir");
    printf("\nIngrear una opción:");
  
    scanf("%d", &option);
    return option;    
}