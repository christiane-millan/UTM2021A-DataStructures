#ifndef DLLIST
#define DLLIST

typedef struct node Node;
typedef struct dlinked_list Dlinked_list;

struct node {
    int data;
    Node *next;
    Node *prev;
};

struct dlinked_list {
    Node *head;
};

Dlinked_list* create_dlinked_list();
Node* create_node(int item);
void destroy_dlinked_list(Node *dlinked_list);
void insert(Node **head, int item);
int delete_node(Node **head, int item);
void display(Dlinked_list *dlinked_list);


#endif