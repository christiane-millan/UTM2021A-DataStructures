#include <stdio.h>
#include <stdlib.h>
#include "bsearch_tree.h"

Bsearch_tree* create_BT(){
   Bsearch_tree *bsearch_tree= (Bsearch_tree *) malloc (sizeof(Bsearch_tree));
   bsearch_tree->root = NULL;
   return bsearch_tree;
}

BTreeNode* create_node(int data){
    BTreeNode *btnode = (BTreeNode *) malloc (sizeof(BTreeNode));
    btnode->data = data;
    btnode->left = NULL;
    btnode->right = NULL;
    return btnode;
}

BTreeNode* insert_node(BTreeNode *node, int data){
    /**
     * If the tree is empty, assign new node to root
     * */
    if(node == NULL){
        node = create_node(data);
        return node;
    }

    /**
     * else, recur down the tree
     * */
    if(data < node->data)
        node->left = insert_node(node->left, data);
    else 
        if(data > node->data)
            node->right = insert_node(node->right, data);
    return node;
}

/*
Dado un árbol binari no vacío, retorna el nodo con el valor clave mínimo
encontrado en el árbol. 
Nota: No tienen que ser búscado en todo el árbol 
*/
BTreeNode* minValueNode(BTreeNode *node){
    BTreeNode *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}


BTreeNode* delete_node(BTreeNode *root, int data){
    // caso base
    if(root == NULL)
        return root;
    // Si el dato a borra es menor que el valor de la raíz
    // pasar al sub-árbol izquierdo
    if( data < root->data)
        root->left = delete_node(root->left, data);
    // Si el dato a borra es mayor que el valor de la raíz
    // pasar al sub-árbol derecho
    else if( data > root->data)
        root->right = delete_node(root->right, data);
    
    // Si el dato es igual al valor de la raíz
    // entonces is el nodo a eliminare
    else {
        // Si el nodo tiene un solo hijo o no tiene hijos
        if(root->left == NULL){
            BTreeNode *temp = root->right;
            free(root);
            return temp;
        } else {
            if (root->right == NULL){
                BTreeNode *temp = root->left;
                free(root);
                return temp;
            }
        }
        //Nodo con dos hijos, tomar los sucesores inorden
        //menores en el sub-árbol derecho
        BTreeNode *temp = minValueNode(root->right);
        //Copiar los sucesores en inorden
        root->data = temp->data;
        //Eliminar los sucesores inorden
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void inorder(BTreeNode *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(BTreeNode *root){
    //TODO
}

void postorder(BTreeNode *root){
    //TODO
}

BTreeNode* search(BTreeNode *root, int data){
    //TODO
    //Implementar la búsqueda de un dato en un árbol binario de búsqueda usando
    //la recursión
    return NULL;
}