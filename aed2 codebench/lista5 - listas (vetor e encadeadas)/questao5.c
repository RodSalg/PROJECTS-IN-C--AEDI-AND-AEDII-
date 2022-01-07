#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode
{
    float id;
} DataNode;

typedef struct node
{
    DataNode data;
    struct node *next;
} Node;

typedef struct list
{
    int size;
    Node *head;
} Lista;

Lista *creatLista1()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));

    l->size = 0;
    l->head = NULL;

    return l;
}

void push(Lista *l, DataNode data)
{
    Node *node = (Node *)malloc(sizeof(Node));

    node->data = data;
    node->next = l->head;
    l->head = node;
}

void printLista(Lista *l)
{
    Node *pointer = l->head;
    while (pointer != NULL)
    {
        printf("%.1f ", pointer->data.id);
        pointer = pointer->next;
    }
    printf("\n");
}

Node *atPos(Lista *l, int index)
{ //devolve o que tem na posicao que eu peço

    if (index >= 0 && index < l->size)
    {
        Node *node = l->head;
        int i;
        for (i = 0; i < index; i++)
            node = node->next;

        return node;
    }
    return NULL;
}

int comprimento(Lista *l)
{

    Node *pointer = atPos(l, 0);
    if (pointer != NULL)
    {
        //Node* maxNode = pointer;
        int cont = 0;

        while (pointer != NULL)
        {
            cont += 1;
            pointer = pointer->next;
        }
        return cont;
    }
}

Lista *merge(Lista *l1, Lista *l2)
{

    Node *t1 = l1->head;
    Node *a1 = l2->head;

    Node *t2 = l1->head->next;
    Node *a2 = l2->head->next;

    /*printf("lista 1: ");
    printLista(list1);

    printf("lista 2: ");
    printLista(list2);*/

    while ((t2 != NULL) && (a2 != NULL))
    {

        t1->next = a1;
        a1->next = t2;
        t1 = t2;
        t2 = t2->next;
        a1 = a2;
        a2 = a2->next;
    }

    t1->next = a1;
    if (a2 == NULL)
    {
        a1->next = t2;
    }

    l2->head = NULL;

    //printf("lista merge: ");
    printLista(l1);
}

int main()
{
    Lista *l1 = creatLista1();
    Lista *l2 = creatLista1();

    DataNode data;

    int tam1, tam2, i;

    scanf("%d", &tam1);
    l1->size = tam1;
    for (i = 0; i < tam1; i++)
    {
        scanf("%f", &data.id);
        push(l1, data);
    }

    scanf("%d", &tam2);
    l2->size = tam2;
    for (i = 0; i < tam2; i++)
    {
        scanf("%f", &data.id);
        push(l2, data);
    }
    merge(l1, l2);
}