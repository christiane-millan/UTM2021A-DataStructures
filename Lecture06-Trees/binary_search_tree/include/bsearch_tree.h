#ifndef BINARYTREE_H

#define BINARYTREE_H

typedef struct node BTreeNode;
typedef struct binary_tree Bsearch_tree;

struct node{
    int data;
    BTreeNode *left;
    BTreeNode *right;
};

struct binary_tree{
    BTreeNode *root;
};

Bsearch_tree* create_BT();
BTreeNode* create_node(int data);
BTreeNode* insert_node(BTreeNode *node, int data);
BTreeNode* delete_node(BTreeNode *root, int data);
BTreeNode* minValueNode(BTreeNode *node);
BTreeNode* search(BTreeNode *root, int data);
void inorder(BTreeNode *root);
void preorder(BTreeNode *root);
void postorder(BTreeNode *root);

#endif