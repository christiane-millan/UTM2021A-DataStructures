#include <stdio.h>
#include "avl_tree.h"

int menu();

int main(){
    AVL_tree* avl_tree = create_AVL();
    /*
              9
            /    \
         1       10 
        /   \       \
      0     5       11
    /      / \
    -1    2   6
       */
    avl_tree->root = NULL;
    avl_tree->root = insert_node(avl_tree->root, 9);
    avl_tree->root = insert_node(avl_tree->root, 5);
    avl_tree->root = insert_node(avl_tree->root, 10);
    avl_tree->root = insert_node(avl_tree->root, 0);
    avl_tree->root = insert_node(avl_tree->root, 6);
    avl_tree->root = insert_node(avl_tree->root, 11);
    avl_tree->root = insert_node(avl_tree->root, -1);
    avl_tree->root = insert_node(avl_tree->root, 1);
    avl_tree->root = insert_node(avl_tree->root, 2);

    printf("Recorrido inorden del árbol:\n");
    inorder(avl_tree->root);

    printf("\nEliminar 10\n");
    avl_tree->root = delete_node(avl_tree->root, 10);
    printf("Recorrido inorden del árbol modificado:\n");
    inorder(avl_tree->root);

    /*
              1
            /    \
         0        9 
        /   \       \
      -1     5       11
            / \
           2   6
    */ 

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