#include <stdio.h>
#include "bsearch_tree.h"

int menu();

int main(){
    Bsearch_tree* bsearch_tree = create_BT();
    /*
              50
            /    \
         30       70 
        /   \   /   \
      20    40  60  80 */
    bsearch_tree->root = NULL;
    bsearch_tree->root = insert_node(bsearch_tree->root, 50);
    bsearch_tree->root = insert_node(bsearch_tree->root, 30);
    bsearch_tree->root = insert_node(bsearch_tree->root, 20);
    bsearch_tree->root = insert_node(bsearch_tree->root, 40);
    bsearch_tree->root = insert_node(bsearch_tree->root, 70);
    bsearch_tree->root = insert_node(bsearch_tree->root, 60);
    bsearch_tree->root = insert_node(bsearch_tree->root, 80);

    printf("Recorrido inorden del árbol:\n");
    inorder(bsearch_tree->root);

    printf("\nEliminar 20\n");
    bsearch_tree->root = delete_node(bsearch_tree->root, 20);
    printf("Recorrido inorden del árbol modificado:\n");
    inorder(bsearch_tree->root);

    printf("\nEliminar 30\n");
    bsearch_tree->root = delete_node(bsearch_tree->root, 30);
    printf("Recorrido inorden del árbol modificado:\n");
    inorder(bsearch_tree->root);

    printf("\nEliminar 50\n");
    bsearch_tree->root = delete_node(bsearch_tree->root, 50);
    printf("Recorrido inorden del árbol modificado:\n");
    inorder(bsearch_tree->root);

    return 0;
}

int menu(){
    int option;
    printf("\n\n\n*** MENÚ ÁRBOL BINARIO***\n");
    printf("\n1. Insertar elemento");
    printf("\n2. Eliminar elemento");
    printf("\n3. Mostrar árbole inorden");
    printf("\n4. Mostrar árbole preorden");
    printf("\n5. Mostrar árbole postorden");
    printf("\n6. Buscar elemento");
    printf("\n7. Salir");
    printf("\nIngrear una opción:");
  
    scanf("%d", &option);
    return option;    
}