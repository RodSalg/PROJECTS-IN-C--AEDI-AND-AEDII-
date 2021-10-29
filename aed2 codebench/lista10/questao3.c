#include <stdio.h>
#include <stdlib.h>

// tamanho da tabela
//#define M 19

// tipo pessoa
typedef struct
{
    int matricula;
    char nome[50];
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

// cria e retorna um tipo pessoa
Pessoa criarPessoa()
{
    Pessoa p;
    printf("Digite o nome da pessoa: ");
    fgets(p.nome, 50, stdin);
    printf("Digite a matricula: ");
    scanf("%d", &p.matricula);
    return p;
}

// imprime uma pessoa
void imprimirPessoa(Pessoa p)
{
    printf("%d %s", p.matricula, p.nome);
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

// busca um elemento na lista
No *buscarNo(int mat, No *inicio)
{

    while (inicio != NULL)
    {
        if (inicio->pessoa.matricula == mat)
        {
            return inicio;
        }
        else
        {
            inicio = inicio->proximo;
        }
    }
    return NULL; // matricula não encontrada
}

void imprimirLista(No *inicio, int indice)
{
    while (inicio != NULL)
    {
        printf("%d ", indice);
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
int funcaoEspalhamento(int mat, int M)
{
    return mat % M;
}

// cria uma pessoa e a insere na tabela
int inserTabela(Lista *tabela[], int M)
{
    Pessoa p;
    // printf("matricula: ");
    scanf("%d", &p.matricula);
    scanf("%*c");

    if (p.matricula != 0)
    {
        // printf("nome: ");
        fgets(p.nome, 50, stdin);
    }
    else
    {
        return p.matricula;
    }

    int indice = funcaoEspalhamento(p.matricula, M);
    inserirFinal(p, tabela[indice]);

    return p.matricula;
}

// busca uma pessoa. Seu retorno é um endereço ou NULL
Pessoa *buscarPessoaTabela(Lista *tabela[], int mat, int M)
{
    int indice = funcaoEspalhamento(mat, M);
    No *no = buscarNo(mat, tabela[indice]->inicio);
    if (no)
    {

        printf("%d %d %s\n", indice, no->pessoa.matricula, no->pessoa.nome);
        return &no->pessoa;
    }
    else
    {
        printf("%d not found\n", mat);
        return NULL;
    }
}

// imprimir tabela
void imprimirTabela(Lista *tabela[], int M)
{
    int i;
    for (i = 0; i < M; i++)
    {
        if (tabela[i]->tam == 0)
        {
            printf("%d null null\n", i);
        }
        else
        {
            // printf("%d ", i);
            imprimirLista(tabela[i]->inicio, i);
        }
    }
}

int main()
{

    int tam;
    int search;
    // tam = 4;
    scanf("%d", &tam);
    Lista *tabela[tam];
    int continua;

    inicializar(tabela, tam);

    do
    {
        continua = inserTabela(tabela, tam);

    } while (continua != 0);
    imprimirTabela(tabela, tam);

    printf("- - -\n");

    scanf("%d", &search);
    while (search != 0)
    {
        buscarPessoaTabela(tabela, search, tam);
        scanf("%d", &search);
    }

    return 0;
}