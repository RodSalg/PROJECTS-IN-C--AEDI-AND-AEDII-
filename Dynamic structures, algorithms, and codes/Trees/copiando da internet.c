#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
    struct node *child;
};

typedef struct node node;

node * new_node(int);
node * add_sibling(node *, int);
node * add_child(node *, int);





int main(int argc, char *argv[]){
    int i;
    node *root = new_node(0);

    for ( i = 1; i <= 3; i++ )
        add_child(root, i);
}





node * new_node(int data)
{
    node *new_node = malloc(sizeof(node));

    if ( new_node ) {
        new_node->next = NULL;
        new_node->child = NULL;
        new_node->data = data;
    }

    return new_node;
}

node * add_sibling(node * n, int data)
{
    if ( n == NULL )
        return NULL;

    while (n->next)
        n = n->next;

    return (n->next = new_node(data));
}

node * add_child(node * n, int data)
{
    if ( n == NULL )
        return NULL;

    if ( n->child )
        return add_sibling(n->child, data);
    else
        return (n->child = new_node(data));
}


