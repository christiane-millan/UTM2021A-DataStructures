#ifndef CLLIST
#define CLLIST

typedef struct node Node;
typedef struct clinked_list Clinked_list;

struct node {
    int data;
    Node *next;
};

struct clinked_list {
    Node *head;
};

Clinked_list* create_clinked_list();
Node* create_node(int item);
void destroy_clinked_list(Node *slinked_list);
void insert(Node **head, int item);
int delete_node(Node **head, int item);
void display(Clinked_list *clinked_list);


#endif