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


    char pai;
    char filho;

    scanf(" %c%*[^\n]",&pai);
    ArvGen* a = cria(pai);
    ArvGen*b;

    
    int flag = 0;
    if(pai == '#' && filho == '#'){
        printf("entrei auqi");
        flag = 1;
    }

    while(flag == 0){

        scanf(" %c%*[^\n]",&pai);
        scanf(" %c%*[^\n]",&filho);
 
        a = cria(pai);
        printf("eu passo");
        insere(a, filho);

        if(pai == '#' && filho == '#'){
            printf("\nachei\n");
            flag = 1;
        }

    }


    imprime(a);


}