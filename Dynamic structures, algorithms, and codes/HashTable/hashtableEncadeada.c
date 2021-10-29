#include <stdio.h>
#include <stdlib.h>

// tamanho da tabela
#define M 19

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
Lista *tabela[M];

//--------------------------------- fim definições variáveis --------------------

//--------------------------------- funções meus tipos --------------------------

// cria e retorna um tipo pessoa
Pessoa criarPessoa()
{
    Pessoa p;
    printf("Digite o nome da pessoa: ");
    scanf("%*c");
    fgets(p.nome, 50, stdin);
    printf("Digite a matricula: ");
    scanf("%d", &p.matricula);
    return p;
}

// imprime uma pessoa
void imprimirPessoa(Pessoa p)
{
    printf("\tNome: %s\tMatricula: %d\n", p.nome, p.matricula);
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

    //primeiramente devo alocar memoria para uma nova pessoa 
    //posteriormente verificar os dois casos
    //primeiro: caso é vazio?
    //se nao for vazio percorrer tudo ate encontrar o ultimo da lista

    No *no = malloc(sizeof(No));

    //agora vou alocar os dados no nó
    no->pessoa = p;

    if(lista->inicio == NULL) //caso ela seja vazia caso que nunca vai acontecer
    {
        lista->inicio = no;
        no->proximo = NULL;
    }else{ //caso exista pelo menos um elemento
        No *aux;
        aux = lista->inicio;

        while(aux)
        {
            if(aux->proximo == NULL)
            {
                aux->proximo = no;
                no->proximo = NULL;
                lista->tam++;

                return no;
            }else{
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
            return inicio;
        else
            inicio = inicio->proximo;
    }
    return NULL; // matricula não encontrada
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
void inicializar()
{
    int i;
    for (i = 0; i < M; i++)
        tabela[i] = criarLista();
}

// função de espalhamento
int funcaoEspalhamento(int mat)
{
    return mat % M;
}

// cria uma pessoa e a insere na tabela
void inserTabela()
{
    Pessoa pes = criarPessoa();
    int indice = funcaoEspalhamento(pes.matricula);
    inserirFinal(pes, tabela[indice]);
}

// busca uma pessoa. Seu retorno é um endereço ou NULL
Pessoa *buscarPessoaTabela(int mat)
{
    int indice = funcaoEspalhamento(mat);
    No *no = buscarNo(mat, tabela[indice]->inicio);
    if (no)
        return &no->pessoa;
    else
        return NULL;
}

// imprimir tabela
void imprimirTabela()
{
    int i;
    printf("\n---------------------TABELA-------------------------\n");
    for (i = 0; i < M; i++)
    {
        printf("%d Lista tamanho: %d\n", i, tabela[i]->tam);
        imprimirLista(tabela[i]->inicio);
    }
    printf("---------------------FIM TABELA-----------------------\n");
}

int main()
{
    int op, mat;
    Pessoa *p;

    inicializar();

    do
    {
        printf("\n0 - Sair\n1 - Inserir\n2 - Buscar\n3 - Imprimir tabela\n");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            printf("saindo...\n");
            break;
        case 1:
            inserTabela();
            break;
        case 2:
            printf("Qual a matricula a ser buscada? ");
            scanf("%d", &mat);
            p = buscarPessoaTabela(mat);
            if (p)
            {
                printf("Pessoa encontrada: Matricula: %d\tNome: %s", p->matricula, p->nome);
            }
            else
                printf("Pessoa nao contrada!\n");
            break;
        case 3:
            imprimirTabela();
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (op != 0);

    return 0;
}