#include <stdio.h>
#include <stdlib.h>

//a tabela funciona agora vou aperfeiçoar para utilizar na q1
//

//constante que representa o tamanho da tabela
//#define M 99
typedef struct
{

    int matricula;

} Pessoa;



//inicializa a tabela com esse valor porque  saberei que posição está preenchida ou nao
void inicializarTabela(Pessoa tabelaHash[], int M)
{
    int i;
    for (i = 0; i < M; i++)
    {
        tabelaHash[i].matricula = -1; //marcamos através da matrícula
    }
}

//funcao de espalhamento
//vai receber a matrícula e gerar um código para salvar o elemento pessoa

int gerarCodigoHash(int chave, int M)
{
    return chave % M; //recebe a chave e retorna o resto da divisao da chave por M;
}


//inserir uma pessoa na tabela;
void inserir(Pessoa tabelaHash[], int mat, int M)
{
    Pessoa pes;
    pes.matricula =  mat;

    int indice = gerarCodigoHash(pes.matricula, M);
    while (tabelaHash[indice].matricula != -1)
    {
        indice = gerarCodigoHash(indice + 1, M);
    }
    tabelaHash[indice] = pes;
}

Pessoa *buscar(Pessoa tabelaHash[], int chave, int M)
{

    int indice = gerarCodigoHash(chave, M);
    while (tabelaHash[indice].matricula != -1)
    {
        if (tabelaHash[indice].matricula == chave)
        {
            return &tabelaHash[indice];
        }
        else
        {
            indice = gerarCodigoHash(indice + 1, M);
        }
    }

    return NULL;
}

void imprimir(
    Pessoa tabelaHash[], int M)
{

    int i;

    for (i = 0; i < M; i++)
    {
        if (tabelaHash[i].matricula != -1)
        {
            printf("%d %d\n", i, tabelaHash[i].matricula);
        }
        else
        {
            printf("%d null \n", i);
        }
    }
}

int main()
{

   
    int tam;
    scanf("%d", &tam);
    int num;
    Pessoa tabelaHash[tam];
    inicializarTabela(tabelaHash, tam);
    scanf("%d", &num);
    while(num != 0)
    {
        inserir(tabelaHash, num, tam);
        scanf("%d", &num);
    }

    imprimir(tabelaHash, tam);
    
   
}