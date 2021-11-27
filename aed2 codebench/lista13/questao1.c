#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// consideraremos tres regras para executar esta estrutura:
/*

    -> toda página possui ao menos 50% de ocupação (manter o balanceamento da árvore);
    -> número de folhas é o número de chaves + 1;
    -> as folhas devem estar sempre no mesmo nível;

*/

// -> structs

// qual a melhor forma? vetor dinâmico?
//  usar ideia do kristian -> tratar como struct cada elemento do vetor;

// vídeo youtube: generalização da árvore binária;

// estudar árvore 2-3-4;

// a árvore possui uma peculiaridade, ela quando bate no chao, acaba subindo!

typedef struct pagina Pagina;

struct pagina
{
    int chave;

    struct pagina *prox;
    struct pagina *esquerda;
    struct pagina *direita;
};

// retorna o tamanho da minha lista de structs na mesma página
// através dele vou poder balancear a árvore
int Quant_Elementos(Pagina *page)
{

    int cont;
    cont = 0;

    Pagina *AuxP;
    AuxP = page;

    while (AuxP)
    {
        AuxP = AuxP->prox;
        cont++;
    }

    return cont;
}

Pagina *Particao(Pagina *page, int ordem)
{
    // printf("entrei na particao\n");
    if (Quant_Elementos(page) == ordem)
    {
        //  printf("ate aqui tudo traqnuilo\n");
        Pagina *aux = page;
        Pagina *auxB;
        int cont = 1;
        while (cont < ((ordem + 1) / 2))
        {
            //   printf("ainda n buguei traqnuilo\n");
            auxB = aux;
            aux = aux->prox; // travessia/
            cont++;
        }
        // printf("vou bugarr\n");
        auxB->prox = NULL;
        auxB->direita = aux->esquerda;
        aux->esquerda = page;
        aux->direita = aux->prox; // suubiu
        aux->prox = NULL;
        // printf("eu vou retornar o aux\n");
        return aux; // quando subir
    }
    // printf("eu vou retornar a pagina\n");
    return page; // caso nao aconteca nada
}

// a funcao insere é semelhante a função da arv binaria  ent...
/*
    seguiremos a lógica da árvore Binária onde:
        menores -> esquerda
        maiores -> direita
    porém para um caso generalizado!
    dessa forma teremos uma mistura de árvore AVL, Binária e Genérica!

*/

Pagina *inserirArvoreB(Pagina *page, int ordem, int chave)
{
    // printf("entrei aqui\n");
    if (page == NULL)
    {
        // printf("1 if\n");
        // caso a página(arvore) seja vazia
        Pagina *NewPage;
        NewPage = (Pagina *)malloc(sizeof(Pagina));

        NewPage->chave = chave;
        NewPage->direita = NULL;
        NewPage->esquerda = NULL;
        NewPage->prox = NULL;

        return NewPage;
    }
    else if (page->chave > chave)
    {
        // printf("2 if\n");
        if (page->esquerda == NULL)
        {
            // printf("3 if\n");
            // agora temos um caso onde existe uma chave e ela é menor, joga p esq
            Pagina *NewPage;
            NewPage = (Pagina *)malloc(sizeof(Pagina));

            NewPage->chave = chave;
            NewPage->direita = NULL;
            NewPage->esquerda = NULL;
            NewPage->prox = page;
            // printf("ate aqui eu ainda funcionao<=====n\n");
            return Particao(NewPage, ordem); // balanceando e mantendo ordem
        }
        else
        {
            // printf("4 if\n");
            int aux;
            aux = Quant_Elementos(page->esquerda);
            page->esquerda = inserirArvoreB(page->esquerda, ordem, chave);
            if (Quant_Elementos(page->esquerda) < aux)
            {
                //    printf("5 if\n");
                page->esquerda->prox = page;
                page = page->esquerda;
                page->prox->esquerda = page->direita;
                page->direita = NULL;
            }
        }
    }
    else if (page->chave < chave)
    {
        // printf("6 if\n");
        if (page->direita == NULL)
        {
            //    printf("7 if\n");
            page->prox = inserirArvoreB(page->prox, ordem, chave);
        }
        else
        {
            //  printf("8 if\n");
            int aux;
            aux = Quant_Elementos(page->direita);
            page->direita = inserirArvoreB(page->direita, ordem, chave);
            if ((Quant_Elementos(page->direita)) < aux)
            {
                // printf("9 if\n");
                page->prox = page->direita;
                page->direita = NULL;
            }
        }
    }
    // printf("10 if\n");

    return Particao(page, ordem);
}

void travessia(Pagina *page) // infixada forma de impressao
{
    if (page != NULL)
    {
        imprime(page->esquerda);
        printf("%d ", page->chave);
        imprime(page->direita);
        imprime(page->prox);
    }
}

void liberaArv(Pagina *page)
{
    if (page != NULL)
    {
        imprime(page->esquerda);
        free(page);
        imprime(page->direita);
        imprime(page->prox);
    }
}

int main(void)
{
    int chave;
    int ordem;
    Pagina *MainPage;
    MainPage = NULL;

    scanf("%d", &ordem);
    scanf("%d", &chave);
    while (chave != 0)
    {
        MainPage = inserirArvoreB(MainPage, ordem, chave);
        scanf("%d", &chave);
    }
    imprime(MainPage);
    liberaArv(MainPage);
}