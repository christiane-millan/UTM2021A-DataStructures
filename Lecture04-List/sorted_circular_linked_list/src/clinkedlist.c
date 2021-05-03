#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "clinkedlist.h"

/**
 * Crear la lista ligada circular, head = NULL
 * */
Clinked_list* create_clinked_list(){
    Clinked_list *clinked_list = (Clinked_list *) malloc (sizeof(Clinked_list));
    clinked_list->head = NULL;
    return clinked_list;
}

/**
 * Crear un nodo para ser agregado a la lista
 * */
Node* create_node(int item){
    Node *new_node = (Node *) malloc (sizeof(Node));
    new_node->data = item;
    new_node->next = new_node;
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
        if (aux->data >= new_node->data){
            while (aux->next != *head)
                aux = aux->next;
            aux->next = new_node;
            new_node->next = *head;
            *head = new_node;
        } else {
            // Caso 3. El valor es mayor y se necesita la posición correcta
            while((aux->next != *head) && (aux->next->data < new_node->data))
                aux = aux->next;
            new_node->next = aux->next;
            aux->next = new_node;
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
            // vericar si head esta apuntado hacia si mismo
            if( (*head)->next == *head){
                data = (*head)->data;
                free(*head);
                *head = NULL;
            } else{
                // Donde hay mas un nodo
                aux = *head;    
                while(aux->next != *head) 
                    aux = aux->next;
                aux->next = (*head)->next;
                Node *temp = *head;
                *head = (*head)->next;
                data = temp->data;
                free(temp);
            }
        } else {
            //caso 2 se desea eliminar un nodo intermedio
            //buscar el nodo previo
            Node *prev = *head;
            while((prev->next != *head) && (prev->next->data != item)){
                prev = prev->next;
            }
            if (prev->next->data == item){
                Node *ax = prev->next;
                prev->next = ax->next;
                data = ax->data;
                free(ax);
            } else {
                data = INT_MAX;
            }
        }
    }
    return data;
}

void display(Clinked_list *clinked_list){
    Node *temp;

    if(clinked_list->head != NULL){
        temp = clinked_list->head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != clinked_list->head);
    }
}