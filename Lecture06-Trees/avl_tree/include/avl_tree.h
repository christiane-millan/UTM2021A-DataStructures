#ifndef AVLTREE_H

#define AVLTREE_H

typedef struct node AVLTreeNode;
typedef struct binary_tree AVL_tree;

struct node{
    int data;
    AVLTreeNode *left;
    AVLTreeNode *right;
    int height;
};

struct binary_tree{
    AVLTreeNode *root;
};

AVL_tree* create_AVL();
AVLTreeNode* create_node(int data);
int height(AVLTreeNode *node);
int max(int a, int b);
int get_balance(AVLTreeNode *node);
AVLTreeNode* right_rotate(AVLTreeNode *y);
AVLTreeNode* left_rotate(AVLTreeNode *x);
AVLTreeNode* insert_node(AVLTreeNode *node, int data);
AVLTreeNode* delete_node(AVLTreeNode *root, int data);
AVLTreeNode* minValueNode(AVLTreeNode *node);
AVLTreeNode* search(AVLTreeNode *root, int data);
void inorder(AVLTreeNode *root);
void preorder(AVLTreeNode *root);
void postorder(AVLTreeNode *root);

#endif