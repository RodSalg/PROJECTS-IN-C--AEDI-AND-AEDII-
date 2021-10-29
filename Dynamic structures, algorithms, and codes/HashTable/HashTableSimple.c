#include <stdio.h>
#include <stdlib.h>

//constante que representa o tamanho da tabela
#define M 99
typedef struct
{

    int matricula;
    char nome[50];

} Pessoa;

Pessoa tabelaHash[M];

//inicializa a tabela com esse valor porque  saberei que posição está preenchida ou nao
void inicializarTabela()
{
    int i;
    for (i = 0; i < M; i++)
    {
        tabelaHash[i].matricula = -1; //marcamos através da matrícula
    }
}

//funcao de espalhamento
//vai receber a matrícula e gerar um código para salvar o elemento pessoa

int gerarCodigoHash(int chave)
{
    return chave % M; //recebe a chave e retorna o resto da divisao da chave por M;
}

//funcao para ler e retornar uma pessoa
Pessoa lerPessoa()
{
    Pessoa p;
    printf("Digite a matricula:");
    scanf("%d", &p.matricula);
    scanf("%*c");
    printf("Digite seu nome:");
    fgets(p.nome, 50, stdin);

    return p;
}

//inserir uma pessoa na tabela;
void inserir()
{
    Pessoa pes = lerPessoa();
    int indice = gerarCodigoHash(pes.matricula);
    while (tabelaHash[indice].matricula != -1)
    {
        indice = gerarCodigoHash(indice + 1);
    }
    tabelaHash[indice] = pes;
}

Pessoa *buscar(int chave)
{

    int indice = gerarCodigoHash(chave);
    while (tabelaHash[indice].matricula != -1)
    {
        if (tabelaHash[indice].matricula == chave)
        {
            return &tabelaHash[indice];
        }
        else
        {
            indice = gerarCodigoHash(indice + 1);
        }
    }

    return NULL;
}

void imprimir()
{

    int i;
    printf("\n--------------- TABELA -----------------\n");
    for (i = 0; i < M; i++)
    {
        if (tabelaHash[i].matricula != -1)
        {
            printf("%d = %d\t %s\n", i, tabelaHash[i].matricula, tabelaHash[i].nome);
        }
        else
        {
            printf("%d = \n", i);
        }
    }
    printf("\n--------------- FIM -----------------\n");
}

int main()
{

    int op;
    int chave;
    Pessoa *p;
    inicializarTabela();
    do
    {

        printf("1 inserire \n 2 buscar \n 3 imprimir \n 0 sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            printf("saindo...\n");
            break;
        case 1:
            printf("dgite a matricula que procura: ");
            scanf("%d", &chave);
            p = buscar(chave);
            if (p)
            {
                printf("\n\t matricula: %d \t nome: %s\n", p->matricula, p->nome);
            }
            else
            {
                printf("\n matricula nao encontrada\n");
            }
            break;
        case 2:
            inserir();
            break;
        case 3:
            imprimir();
            break;
        default:
            printf("opcao invalida");
        }

    } while (op != 0);
}