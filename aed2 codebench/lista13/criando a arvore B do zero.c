#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

typedef struct NoArvore //BTreeNode
{

    int *chaves; //vetor c elementos do nó
    int contador; // contador do tamanho de elementos que foram  ???
    struct NoArvore *filhos; // vetor dinamico para filhos na hora de criar vou criar um vetor din

}NoArvore;

NoArvore *createNode(int chave, NoArvore *filho, NoArvore raiz, int ordem)
{

    NoArvore *No;
    No = (NoArvore *)malloc(sizeof(NoArvore));
    int *VetChave;
    VetChave = (int *)malloc ( (ordem -1) * sizeof(int));
    int *VetFilhos;
    VetFilhos = malloc(ordem * sizeof(NoArvore*));

    No->chaves = VetChave;
    No->filhos = VetFilhos;

    No->chaves[1] = chave;
    No->contador = 1;
    No->filhos[0] = raiz;

    return No;

}


void inserirNo(int chave, int pos, NoArvore *no, NoArvore filho)
{

    int i;
    i = no->contador;
    while(i > pos)
    {
        no->chaves[i + 1] = no->chaves[i];
        no->filhos[i + 1] = no->filhos[i];
        i--;
    }
    no->chaves[i+1] = chave;
    no->filhos[i+1] = filho;
    no->contador++;

}

//particao como funciona
void particaoNo(int chave, int *pchave, int pos, NoArvore *no, NoArvore filho, NoArvore **novoNo, int ordem)
{
    int mediano;
    int j;

    if(pos > (ordem - 1) )
    {
        mediano = (ordem-1) + 1 ;
    }else{
        mediano = ordem - 1;
    }

    *novoNo = (NoArvore *)malloc(sizeof(NoArvore));
    j = mediano + 1;

    while(j <= ordem)
    {
        (*novoNo)->chaves[j - mediano] = no->chaves[j];
        (*novoNo)->filhos[j - mediano] = no->filhos[j];
        j++;
    }

    no->contador = mediano;
    (*novoNo)->contador = ordem - mediano;

    if(pos <= (ordem -1))
    {
        inserirNo(chave, pos, no, filho);
    }else{
        inserirNo(chave, pos - mediano, *novoNo, filho);
    }

    *pchave = no->chaves[no->contador];
    (*novoNo)->filhos[0] = no->filhos[no->contador];
    no->contador--;

}

int PreparandoChave(int chave, int *pchave, NoArvore *no, NoArvore **filho, int ordem)
{
    int pos;
    if(!no)
    {
        *pchave = chave;
        *filho = NULL;
    }

    if(chave < no->filhos[1])
    {
        pos =0;
    }else{
        for(pos = no->contador; chave < no->chaves[pos] && pos > 1; pos--);
        if(chave == no->chaves[pos])
        {
            printf("n pode duplicacoes\n");
            return 0;
        }
    }
    if(PreparandoChave(chave, pchave, no->filhos[pos],filho))
    {
        if(no->contador < ordem)
        {
            inserirNo(*pchave, pos, no, *filho);
        }else{
            particaoNo(*pchave, pchave, pos, no, *filho, filho);
            return 1;
        }
    }

    return 0;

}

int main()
{

    //NoArvore *raiz;


}