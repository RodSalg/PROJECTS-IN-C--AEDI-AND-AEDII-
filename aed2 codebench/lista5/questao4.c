#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNo tipoNo;
typedef struct tipoAgenda{
    
    int numero; //altura

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
    printf(" %d\n", a.numero);
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

void mostraListaInvertida(tipoLista *l, tipoNo *aux){
    
    if(aux == NULL){
        printf("%d", l->prim->info.numero);
    }else{
        mostrarInfo(aux->info);
        aux = aux->prox;
        mostraListaInvertida(l, aux);
    }
}

int main(){

    
    tipoLista *lista;
    tipoAgenda a;
    
    lista = criarLista();

    scanf("%d", &a.numero);
 
    while(a.numero > 0 && a.numero != 0){    

        inserirFinalLista(lista, a);
        scanf("%d", &a.numero);
    }  

    tipoNo *aux = lista->prim;
    mostrarLista(lista);  
    mostraListaInvertida(lista, aux);






    
    





    return 0;
}