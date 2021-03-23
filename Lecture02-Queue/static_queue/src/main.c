#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "queue.h"

int menu();

int main(){
    Queue *queue = create_queue(10);
    int option, item;

    while(1){
        option = menu();
        switch (option)
        {
        case 1: printf(("Ingresa un elemento "));
                scanf("%d", &item);
                enqueue(queue, item);
                break;
        case 2: item = dequeue(queue);
                if(item != INT_MIN)
                    printf("Elemento retirado: %d", item);
                else
                    printf("Cola esta vacía");
                break;
        case 3: item = peek(queue);
                if(item == INT_MIN)
                    printf("No hay elementos en la cola");
                else
                    printf("Elemento al frente de la cola: %d", item);
                break;
        case 4: display(queue);
                break;
        case 5: destroy_queue(queue);
                exit(0);
        
        default:printf("\nOpción inválida");
            break;
        }
    }
}

int menu(){
  int option;
  printf("\n\n\n*** MENU COLA-QUEUE***\n");
  printf("\n1. Insertar elemento");
  printf("\n2. Eliminar elemento");
  printf("\n3. Mirar elemento de front");
  printf("\n4. Mostrar elementos de la cola");
  printf("\n5. Salir");
  printf("\nIngrear una opción:");
  
  scanf("%d", &option);
  return option;
}