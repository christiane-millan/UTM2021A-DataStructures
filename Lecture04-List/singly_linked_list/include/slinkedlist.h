#ifndef SLLIST
#define SLLIST

typedef struct node Node;
typedef struct slinked_list Slinked_list;

struct node {
    int data;
    Node *next;
};

struct slinked_list {
    Node *head;
};

Slinked_list* create_slinked_list();
Node* create_node(int item);
void destroy_slinked_list(Node *slinked_list);
void insert_head(Node **head_ref, int item);
void insert_end(Node **head_ref, int item);
void insert_after(Node **prev_node, int item);
int delete_head(Node **head_ref);
int delete_after(Node **prev_node);
void display(Slinked_list *slinked_list);
void insert(Node *head, int item);

#endif