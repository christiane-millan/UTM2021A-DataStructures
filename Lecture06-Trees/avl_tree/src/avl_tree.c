#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

AVL_tree* create_AVL(){
   AVL_tree *avl_tree= (AVL_tree *) malloc (sizeof(AVL_tree));
   avl_tree->root = NULL;
   return avl_tree;
}

AVLTreeNode* create_node(int data){
    AVLTreeNode *avltnode = (AVLTreeNode *) malloc (sizeof(AVLTreeNode));
    avltnode->data = data;
    avltnode->left = NULL;
    avltnode->right = NULL;
    avltnode->height = 1;
    return avltnode;
}

//Utility function to get maximum of two integers
int max(int a, int b){
    return (a > b)? a : b;
}

// Utility function to get the height of the tree
int height(AVLTreeNode *node){
    if(node == NULL)
        return 0;
    return node->height;
}

//get balance factor of node 
int get_balance(AVLTreeNode *node){
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

//A utility function to right rotate subtree rooted with y
//see the diagram give slides.
AVLTreeNode* right_rotate(AVLTreeNode *y){
    AVLTreeNode *x = y->left;
    AVLTreeNode *T2 = x->right;

    //Perform rotation
    x->right = y;
    y->left = T2;

    //Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    //return new root
    return x;
}

AVLTreeNode* left_rotate(AVLTreeNode *x){
    AVLTreeNode *y = x->right;
    AVLTreeNode *T2 = y->left;

    //Perform rotation
    y->left = x;
    x->right = T2;

    //Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    //Return new root
    return y;
    
}

AVLTreeNode* insert_node(AVLTreeNode *node, int data){
    /**
     * 1. Perform the normal BST insertion
     * */
    if(node == NULL)
        return (create_node(data));

    if(data < node->data)
        node->left = insert_node(node->left, data);
    else 
        if(data > node->data)
            node->right = insert_node(node->right, data);
    return node;
    /**
     * 2. Update height of this ancestor node
     * */
    node->height = 1 + max(height(node->left), height(node->right));
    /**
     * 3. Get the balance factor of this ancestor node to check wheter this 
     * node became unbalance
     * */
    int balance = get_balance(node);

    //if this node becames unbalanced, then there are 4 cases

    //LL Rotate
    if(balance > 1 && data < node->left->data)
        return right_rotate(node);

    //RR Rotate
    if(balance < -1 && data > node->right->data)
        return left_rotate(node);
    
    //LR Rotate
    if(balance > 1 && data > node->left->data){
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    //RL Rotate
    if(balance < -1 && data < node->right->data){
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    /**
     * Return the (unchanged) node pointer
     * */
    return node;
}

/*
Dado un árbol binari no vacío, retorna el nodo con el valor clave mínimo
encontrado en el árbol. 
Nota: No tienen que ser búscado en todo el árbol 
*/
AVLTreeNode* minValueNode(AVLTreeNode *node){
    AVLTreeNode *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}


AVLTreeNode* delete_node(AVLTreeNode *root, int data){
    // PASO 1. Ejecutar eliminación estándar BST
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
        if((root->left == NULL) || (root->right == NULL)){
            AVLTreeNode *temp = root->left? root->left : root->right;

            // nodo sin hijos
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            } 
            else 
            {
                *root = *temp;
            }
            free(root);
        } else {
            //Nodo con dos hijos, tomar los sucesores inorden
            //menores en el sub-árbol derecho
            AVLTreeNode *temp = minValueNode(root->right);
            //Copiar los sucesores en inorden
            root->data = temp->data;
            //Eliminar los sucesores inorden
            root->right = delete_node(root->right, temp->data);   
        }
        
    }

    //si el noodo tiene solo un nodo retornar
    if (root == NULL)
    {
        return root;
    }

    //Paso 2. Actualizar los pesos del nodo actual
    root->height = 1 + max(height(root->left), height(root->right));
    
    //Paso 3. Obtener el facto de balance de este nodo
    int balance = get_balance(root);
    
    //Si el nodo se queda desbalanceado, entonces considerar los cuatro casos
    //LL Rotate
    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);
    
    //LR Rotate
    if (balance > 1 && get_balance(root->left) < 0)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    //RR Rotate
    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);
    
    //RL Rotate
    if (balance < -1 && get_balance(root->right) > 0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    
    return root;
}

void inorder(AVLTreeNode *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// void preorder(AVLTreeNode *root){
//     //TODO
// }

// void postorder(AVLTreeNode *root){
//     //TODO
// }

// AVLTreeNode* search(AVLTreeNode *root, int data){
//     //TODO
//     //Implementar la búsqueda de un dato en un árbol binario de búsqueda usando
//     //la recursión
//     return NULL;
// }