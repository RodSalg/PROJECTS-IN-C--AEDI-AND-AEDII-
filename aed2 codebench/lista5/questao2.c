#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNo tipoNo;
typedef struct tipoAgenda{
    
    int numero;

}tipoAgenda;

typedef struct tipoNo{
    tipoAgenda info;
    tipoNo *prox;
}tipoNo;


typedef struct tipoLista{
    tipoNo* prim;

}tipoLista;


tipoLista* criarLista(){
    tipoLista *l;
    l = malloc(sizeof(tipoLista));
    l->prim = NULL;

    return l;

}

void mostrarInfo(tipoAgenda a){
    printf("num: %d\n", a.numero);
}

void inserirLista(tipoLista *l, tipoAgenda a){
    tipoNo* no;
    no = (tipoNo*)malloc(sizeof(tipoNo));
    no->info = a;
    no->prox = l->prim;
    l->prim = no;

}

void inserirFinalLista(tipoLista *l, tipoAgenda a){

    tipoNo* no;
    no = (tipoNo*)malloc(sizeof(tipoNo));
    no->info = a;
    no->prox = NULL;

    if(l->prim == NULL){
        l->prim = no;
    }else{
        tipoNo *aux = l->prim;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;

    }

    

}



void mostrarLista(tipoLista *l){//com ponteiro{
    tipoNo *aux = l->prim;
    while(aux){
        mostrarInfo(aux->info);
        aux = aux->prox;
    }
}


int comum(tipoLista l, tipoLista l2){
    printf("entrei na funcao\n");
    tipoLista aux;
    aux = l2;
    while(l.prim){  //posicao 0
        l2 = aux;
    printf("entrei no 1 while\n");

        while(l2.prim){
            printf("entrei no 2 while\n");
            
            if(l.prim->info.numero == l2.prim->info.numero){
                printf("\ncomparando [%d] com [%d]\n", l.prim->info.numero, l2.prim->info.numero);
                return 1;
            }

            printf("\n [%d] e  [%d] nao sao iguais\n", l.prim->info.numero, l2.prim->info.numero);

            l2.prim = l2.prim->prox;
        }
        
        l.prim = l.prim->prox;
    }

    return 0;

}



int main(){

    
    tipoLista *lista;
    tipoLista *lista2;
    tipoAgenda a;
    lista = criarLista();
    lista2 = criarLista();


    scanf("%d", &a.numero);
    while(a.numero != 0){

        inserirFinalLista(lista, a);
        scanf("%d", &a.numero);
    }


    scanf("%d", &a.numero);
    while(a.numero != 0){

        inserirFinalLista(lista2, a);
        scanf("%d", &a.numero);
    }          

    mostrarLista(lista);
    printf("\n");
    mostrarLista(lista2);
    printf("\n");

    if( comum(*lista, *lista2) == 0){
        printf("NAO");
    }else{
        printf("SIM");
    }
        
    
    





    
    





    return 0;
}