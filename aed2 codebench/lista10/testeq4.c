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
    //printf("eu entro na funcao mas nao adiciono\n");

    // 1° caso: não há elemento na raíz
    if (root == NULL)
    {

        Node *aux = (Node *)malloc(sizeof(Node)); // aloco memoria para um nó
        // printf("sou a raiz [%d]\n", x.num);

        aux->item = x;
        aux->left = treeinitialize();
        aux->right = treeinitialize();
        //printf("vou inserir na novidades\n");

        return aux; // retorno o no que eu adicionei;
    }else if(root != NULL){ // caso o nó nao seja nula ( ARVORE BINARIA DE BUSCA )

        if (x.num > root->item.num)
        { // se o numero for maior vai entrar na direita
            //printf("vou inserir na direita\n");
            root->right = treeInsert(root->right, x);
            // printf("fui para a direita [%d]\n", x.num);
        }
        else if (x.num < root->item.num)
        { // caso o numero seja menor ele vai entrar na esquerda
            //printf("vou inserir na esquerda\n");
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
        
        treePrint(root->left);
        printf("%d %s ", root->item.num, root->item.Nome);
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



























//--------------------------- início funções tabela hash -----------------------

// inicializa a tabela com uma lista vazia em cada posição do vetor

Node *criarLista()
{
    Node *root = treeinitialize();

    return root;
}


void inicializar(Node *tabela[], int M)
{
    int i;
    for (i = 0; i < M; i++)
        tabela[i] = criarLista();
}

// função de espalhamento
int funcaoEspalhamento(int mat, int M)
{
    return mat % M;
}

// cria uma pessoa e a insere na tabela
void inserTabela(Node *tabela[], int M, Node p)
{

    int indice = funcaoEspalhamento(p.item.num, M);
    tabela[indice] = treeInsert(tabela[indice], itemCreate(p.item.num, p.item.Nome));
    //mandar inserir, (root, na posicao)
    

}

// busca uma pessoa. Seu retorno é um endereço ou NULL
Item *buscarPessoaTabela(Node *tabela[], int mat, int M)
{
    int indice = funcaoEspalhamento(mat, M);
    Node *pessoa;
    pessoa = treeSearch(tabela[indice], mat);

    if(pessoa)
    {
        printf("%d %d %s\n", indice, pessoa->item.num, pessoa->item.Nome);
    }else
    {
        printf("%d not found\n", mat);
    }
}

// imprimir tabela

void imprimirTabela(Node *tabela[], int M)
{
    int i;
    for (i = 0; i < M; i++)
    {
        if (tabela[i] == NULL)
        {
            printf("%d null \n", i);
        }
        else
        {
            printf("%d ", i);
            treePrint(tabela[i]);
            printf("\n");
        }
    }
}


























int main()
{

    Node *tabela[4];
    Node aux;
    int tam;
    scanf("%d", &tam);
    inicializar(tabela, tam);


    /*root = treeInsert(root, itemCreate(10, "rod"));
    root = treeInsert(root, itemCreate(15, "rod"));
    root = treeInsert(root, itemCreate(20, "rod"));
    root = treeInsert(root, itemCreate(12, "rod"));
    root = treeInsert(root, itemCreate(5, "rod"));

    printf(" >> antes de remover \n");
    treePrint(root);
    root = treeRemove(root, 10);
    printf("\n >>depois de remover \n");*/


 
    scanf("%d", &aux.item.num);
    if (aux.item.num != 0)
    {
        scanf("%s", &aux.item.Nome);
        //printf("buguei1\n");

        //printf("buguei\n");
    }

    while (aux.item.num != 0)
    {
        inserTabela(tabela, tam, aux);
        scanf("%d", &aux.item.num);
        if (aux.item.num != 0)
        {
            scanf("%s", &aux.item.Nome);
        }
        
    }

    //printf("%d %s", tabela[1]->item.num, tabela[1]->item.Nome);
    imprimirTabela(tabela, tam);
    printf("- - -\n");
    int search;
    scanf("%d", &search);
    while (search != 0)
    {
        buscarPessoaTabela(tabela, search, tam);
        scanf("%d", &search);
    }

    return 0;
}