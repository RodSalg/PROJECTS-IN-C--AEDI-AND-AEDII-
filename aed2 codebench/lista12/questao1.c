#include <stdio.h>
#include <stdlib.h>

// tamanho da tabela
//#define M 19

// tipo pessoa
typedef struct
{
    int matricula;
} Pessoa;

// tipo nó usado na lista encadeada
typedef struct no
{
    Pessoa pessoa;
    struct no *proximo;
} No;

// tipo lista com um ponteiro para o primeiro nó
typedef struct
{
    No *inicio;
    int tam;
} Lista;

// nossa tabela (vetor de ponteiros para listas)
// Lista *tabela[M];

//--------------------------------- fim definições variáveis --------------------

//--------------------------------- funções meus tipos --------------------------

// imprime uma pessoa
void imprimirPessoa(Pessoa p)
{
    printf("%d ", p.matricula);
}

//-------------------------------- início funções lista -------------------------
// cria uma lista vazia e retorna seu endereço na memória
Lista *criarLista()
{
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tam = 0;
    return l;
}

/*
    inserir no início da lista
    PARÂMETROS
    p - nova pessoa a ser inserida
    *lista - endereço de uma lista encadeada.
*/

void inserirInicio(Pessoa p, Lista *lista)
{
    No *no = malloc(sizeof(No)); //

    no->pessoa = p;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}

No *inserirFinal(Pessoa p, Lista *lista)
{

    // primeiramente devo alocar memoria para uma nova pessoa
    // posteriormente verificar os dois casos
    // primeiro: caso é vazio?
    // se nao for vazio percorrer tudo ate encontrar o ultimo da lista

    No *no = malloc(sizeof(No));

    // agora vou alocar os dados no nó
    no->pessoa = p;

    if (lista->inicio == NULL) // caso ela seja vazia caso que nunca vai acontecer
    {
        lista->inicio = no;
        no->proximo = NULL;
        lista->tam++;
    }
    else
    { // caso exista pelo menos um elemento
        No *aux;
        aux = lista->inicio;

        while (aux)
        {
            if (aux->proximo == NULL)
            {
                aux->proximo = no;
                no->proximo = NULL;
                lista->tam++;

                return no;
            }
            else
            {
                aux = aux->proximo;
            }
        }

        return NULL;
    }
}

void imprimirLista(No *inicio)
{
    while (inicio != NULL)
    {
        imprimirPessoa(inicio->pessoa);
        inicio = inicio->proximo;
    }
}
//---------------------------------- fim funções lista -------------------------

//--------------------------- início funções tabela hash -----------------------
// inicializa a tabela com uma lista vazia em cada posição do vetor
void inicializar(Lista *tabela[], int M)
{
    int i;
    for (i = 0; i < M; i++)
        tabela[i] = criarLista();
}

// função de espalhamento
int funcaoEspalhamento(int mat, int baldes, int tam)
{
    int a = (mat * baldes) / (tam + 1);
    return a;
}

// cria uma pessoa e a insere na tabela
int inserTabela(Lista *tabela[], int baldes, int tam, int ele)
{
    Pessoa p;
    // printf("matricula: ");

    p.matricula = ele;

    if (p.matricula < 1 || p.matricula > tam)
    {
        while (p.matricula < 1 || p.matricula > tam)
        {
            scanf("%d", &p.matricula);
        }
    }

    int indice = funcaoEspalhamento(p.matricula, baldes, tam);
    inserirFinal(p, tabela[indice]);

    return p.matricula;
}

void ordena(int quadro[], int tam)
{
    int i;
    int j;
    int min;
    int aux;
    for (i = 0; i < (tam - 1); i++)
    {
        min = i;

        for (j = (i + 1); j < tam; j++)
        {
            if (quadro[j] == quadro[min])
            {
                min = j;
            }
            else
            {
                if (quadro[j] < quadro[min])
                {
                    min = j;
                }
            }
        }
        if (i != min)
        {
            aux = quadro[i];
            quadro[i] = quadro[min];
            quadro[min] = aux;
        }
    }

    //imprimeVetor(quadro, tam);
}

void imprimeVetor(int vetor[], int tam)
{
    printf("\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vetor[i]);
    }
}


void imprimirTabela(Lista *tabela[], int M)
{
    int i;
    for (i = 0; i < M; i++)
    {
        if (tabela[i]->tam == 0)
        {
            printf("%d NULL \n", i);
        }
        else
        {
            printf("%d ", i);
            imprimirLista(tabela[i]->inicio);
            printf("\n");
        }
    }
}

void imprime_sort(Lista *tabela[], int M)
{
    int i;
    for (i = 0; i < M; i++)
    {
        if (tabela[i]->tam == 0)
        {
            printf("", i);
        }
        else
        {
            imprimirLista(tabela[i]->inicio);
        }
    }
}

int main()
{

    int tam;
    int baldes;
    int quantidade;

    scanf("%d", &baldes);
    scanf("%d", &quantidade);
    scanf("%d", &tam);

    int vetor[quantidade];

    Lista *tabela[baldes];
    

    inicializar(tabela, baldes);
    for (int i = 0; i < quantidade; i++)
    {
        // printf("entrei no for\n");
        //inserTabela(tabela, baldes, tam);
        scanf("%d", &vetor[i]);

    }

    ordena(vetor, quantidade);

    for (int i = 0; i < quantidade; i++)
    {
        // printf("entrei no for\n");
        inserTabela(tabela, baldes, tam, vetor[i]);
    }
    printf("\n");
    imprimirTabela(tabela, baldes);
    imprime_sort(tabela, baldes);
    

    return 0;
}