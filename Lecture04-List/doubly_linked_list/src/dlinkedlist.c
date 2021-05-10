#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "dlinkedlist.h"

/**
 * Crear la lista ligada doble, head = NULL
 * */
Dlinked_list* create_dlinked_list(){
    Dlinked_list *dlinked_list = (Dlinked_list *) malloc (sizeof(Dlinked_list));
    dlinked_list->head = NULL;
    return dlinked_list;
}

/**
 * Crear un nodo para ser agregado a la lista
 * */
Node* create_node(int item){
    Node *new_node = (Node *) malloc (sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insert(Node **head, int item){
    Node *new_node = create_node(item);
    Node *aux = *head; 
    // Caso 1. Si lista esta vacía
    if (*head == NULL){
        //new_node->next = new_node; en crear
        *head = new_node;
    } else {
        // Caso 2. si el valor es menor al head
        if (new_node->data <= (*head)->data){
            new_node->next = *head;
            (*head)->prev = new_node;
            *head = new_node;
        } else {
            // Caso 3 y 4. Si el valor es el mayor va al final de la lista
            int b = 0;
            while((aux->next != NULL) && (b == 0)){
                if(aux->next->data > new_node->data){
                    //Caso 4. después de un nodo dado (un nodo de referencia)
                    aux->next->prev = new_node;
                    new_node->next = aux->next;
                    new_node->prev = aux;
                    aux->next = new_node;
                    b = 1;
                }
                aux = aux->next;
            }
            // Caso 3. colocar el nuevo nodo al final de la lista
            if ( b == 0) {
                aux->next = new_node;
                new_node->prev = aux;
            }
        }
    }
}

int delete_node(Node **head, int item){
    Node *aux;
    int data = INT_MIN;
    // verficar que la lista no esta vacia
    if ( *head == NULL) {
        data = INT_MIN;
    } else {
        //caso 1 se desea eliminar el nodo que esta en head
        if( (*head)->data == item){
            // vericar si head esta apuntado hacia NULL
            if( (*head)->next == NULL){
                data = (*head)->data;
                free(*head);
                *head = NULL;
            } else{
                // Donde hay más un nodo
                aux = *head; 
                *head = (*head)->next;   
                (*head)->prev = NULL;
                aux->next = NULL;
                data = aux->data;
                free(aux);
            }
        } else {
            //caso 2 y 3se desea eliminiar el último nodo o un nodo intermedio
            aux = *head;
            int b = 0;
            while((aux->next != NULL) && (b == 0)){
                if (aux->next->data == item){
                    Node *temp = aux->next;
                    // Caso 2 eliminar el nodo final
                    if(aux->next->next == NULL){
                        aux->next = NULL;
                        temp->prev = NULL;
                        data = temp->data;
                        free(temp);
                        b = 1;
                        return data;
                    } else {
                        // Caso 3
                        aux->next = temp->next;
                        temp->next->prev = aux;
                        temp->next = NULL;
                        temp->prev = NULL;
                        data = temp->data;
                        free(temp);
                        b = 1;
                        return data;
                    }
                }
                aux = aux->next;
            }
        }
    }
    return data;
}

void display(Dlinked_list *dlinked_list){
    Node *temp;

    if(dlinked_list->head != NULL){
        temp = dlinked_list->head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != NULL);
    }
}