#include <stdio.h>
#include <stdlib.h>

struct arvgen{

    char info;
    struct arvgen *prim;
    struct arvgen *prox;
};

typedef struct arvgen ArvGen;


ArvGen* cria (char c){

    ArvGen* a =(ArvGen*)malloc(sizeof(ArvGen));

    a->info = c;
    a->prim = NULL;
    a->prox = NULL;

    return a;

}


void insere(ArvGen* a, ArvGen* f){

    f->prox = a->prim;
    a->prim = f;

}


void imprime(ArvGen* a){

    ArvGen* p;
    printf("%c\n", a->info);

    for (p = a->prim; p != NULL; p = p->prox){
        imprime(p);
    }
    
}

void libera(ArvGen* a){

    ArvGen* p = a->prim;

    while (p != NULL){

        ArvGen* t = p->prox;
        libera(p);
        p = t;
    }

    free(a);
}


int main(){




    ArvGen* a = cria('a');
    ArvGen* b = cria('b');
    ArvGen* c = cria('c');
    ArvGen* d = cria('d');
    ArvGen* e = cria('e');
    ArvGen* f = cria('f');
    ArvGen* g = cria('g');
    ArvGen* h = cria('h');
    ArvGen* i = cria('i');
    ArvGen* j = cria('j');


    insere(a,b);
    insere(b,c);
    insere(a,f);
    insere(a,g);
    insere(b,e);
    insere(c,d);
    insere(g,h);
    insere(g,i);
    insere(i,j);
    
    
    
    
    

    imprime(a);


}