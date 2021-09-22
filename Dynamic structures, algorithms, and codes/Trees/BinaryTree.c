#include <stdio.h>
#include <stdlib.h>

// ======================================= Binary Tree ========================================
// =================================== by Rodrigo Salgado======================================
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




int main(){



}