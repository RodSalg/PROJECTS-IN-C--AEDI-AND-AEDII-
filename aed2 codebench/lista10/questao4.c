#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item
{
    int num;
    char Nome[50];
};
typedef struct item Item;

struct node
{

    Item item;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

// funcoes

Node *treeinitialize()
{

    return NULL;
}

Item itemCreate(int cod, char novonome[])
{

    Item item;
    item.num = cod;
    strcpy(item.Nome, novonome);

    return item;
}

Node *treeInsert(Node *root, Item x)
{ // fazendo de uma forma mais abstrata

    // quais sao os casos?

    // 1° caso: não há elemento na raíz
    if (root == NULL)
    {

        Node *aux = (Node *)malloc(sizeof(Node)); // aloco memoria para um nó
        // printf("sou a raiz [%d]\n", x.num);

        aux->item = x;
        aux->left = treeinitialize();
        aux->right = treeinitialize();

        return aux; // retorno o no que eu adicionei;
    }
    else
    { // caso o nó nao seja nula ( ARVORE BINARIA DE BUSCA )

        if (x.num > root->item.num)
        { // se o numero for maior vai entrar na direita

            root->right = treeInsert(root->right, x);
            // printf("fui para a direita [%d]\n", x.num);
        }
        else if (x.num < root->item.num)
        { // caso o numero seja menor ele vai entrar na esquerda

            root->left = treeInsert(root->left, x);
            // printf("fui para a esquerda [%d]\n", x.num);
        }
    }

    return root;
}

// imprimir a arvore

void treePrint(Node *root)
{

    // sempre verificar se é vazia ou nao
    if (root)
    {
        printf("[%d] %s\n", root->item.num, root->item.Nome);
        treePrint(root->left);
        treePrint(root->right);
    }
}

void treeFree(Node *root)
{

    // sempre verificar se é vazia ou nao
    if (root)
    {

        treeFree(root->left);
        treeFree(root->right);
        free(root);
    }
}

// procurando algo na arvore

Node *treeSearch(Node *root, int cod)
{

    if (root)
    {
        if (root->item.num == cod)
        {
            return root;
        }
        else
        {
            if (cod > root->item.num)
            {
                return treeSearch(root->right, cod);
            }
            else
            {
                return treeSearch(root->left, cod);
            }
        }
    }

    return NULL;
}

int main()
{

    Node *root = treeinitialize(); // raíz é nula;

    root = treeInsert(root, itemCreate(10, "rod"));
    root = treeInsert(root, itemCreate(15, "rod"));
    root = treeInsert(root, itemCreate(20, "rod"));
    root = treeInsert(root, itemCreate(12, "rod"));
    root = treeInsert(root, itemCreate(5, "rod"));

    printf(" >> antes de remover \n");
    treePrint(root);
    root = treeRemove(root, 10);
    printf("\n >>depois de remover \n");

    /*int numero;
    char nome[50];

    scanf("%d", &numero);
    if (numero != 0)
    {
        scanf("%s", nome);
    }
    while (numero != 0)
    {
        root = treeInsert(root, itemCreate(numero, nome));
        scanf("%d", &numero);
        if(numero != 0)
        {
            scanf("%s", nome);
        }

    }*/

    treePrint(root);

    treeFree(root);

    return 0;
}