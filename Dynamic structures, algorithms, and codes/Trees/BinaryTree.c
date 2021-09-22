#include <stdio.h>
#include <stdlib.h>

// ======================================= Binary Tree ========================================
// =================================== by Rodrigo Salgado ======================================
// ============================================================================================

typedef struct arv Arv;
struct arv {
    
    char info;
    struct arv* esq;
    struct arv* dir;

};

Arv *inicializa(void){ //simplesmente retorna vazio; Ajuda a definir que um nó nao tem sequencia nem pela SAE nem SAD )

    return NULL;
}

int vazia(Arv* a){ //verifica se a árvore é vazia

    return a == NULL;

}

Arv* cria(char c, Arv* sae, Arv* sad)
{
    Arv* p = (Arv*) malloc(sizeof(Arv)); //alocando memória para a struct árvore

    p->info = c; //
    p->esq = sae;
    p->dir = sad;


    return p;

}

void imprime(Arv* a)
{
    if (!vazia(a)){

    printf("%c ", a->info); /* mostra raiz */
    imprime(a->esq); /* mostra sae */
    imprime(a->dir); /* mostra sad */

    }
}

Arv* libera(Arv* a){

    if (!vazia(a)){

        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */

        free(a); /* libera raiz */

    }
    return NULL;
}


int busca(Arv *a, char c){
    if (vazia(a))
        return 0; /* não encontrou */
    else
        return a->info == c ||
            busca(a->esq, c) ||
            busca(a->dir, c);

}


int main(){



}