#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo tipoNo;
typedef struct tipoAluno{

    int numero;
}tipoAluno;

typedef struct tipoNo{
    tipoAluno info;
    tipoNo *prox;
    tipoNo *ant;
}tipoNo;


typedef struct tipoLista{
    tipoNo* prim;
    tipoNo* ult;

}tipoLista;


tipoLista* criarLista(){
    tipoLista *l;
    l = malloc(sizeof(tipoLista));
    l->prim = NULL;
    l->ult = NULL;

    return l;

}

void mostrarInfo(tipoAluno a){
    printf("%d ",a.numero);
}

void inserirLista(tipoLista *l, tipoAluno a){
    tipoNo* no;
    no = (tipoNo*)malloc(sizeof(tipoNo));
    no->info = a;

    no->ant = NULL;
    no->prox = l->prim;
    

    l->prim = no;
    if(l->ult == NULL){
        l->ult = no;
    }

}

void inserirFinalLista(tipoLista *l, tipoAluno a){

    tipoNo* no;
    no = (tipoNo*)malloc(sizeof(tipoNo));
    no->info = a;
    
    no->prox = NULL;
    no->ant = l->ult;

    l->ult = no;
   
    if(l->prim == NULL){
        l->prim = no;
    }else{
         l->ult->ant->prox = no;
    }
}


void mostrarLista(tipoLista l){ //sem ponteiro
    
    while(l.prim){
        mostrarInfo(l.prim->info);
        l.prim = l.prim->prox;
    }
}

void mostraListaInvertida(tipoLista *l, tipoNo *aux){
    
    if(aux->ant == NULL){
        mostrarInfo(aux->info); 
    }else{

        mostrarInfo(aux->info);
        aux = aux->ant;
        mostraListaInvertida(l, aux);
    }
}


int main(){

    
    tipoLista *lista;
    tipoAluno a;
    
    lista = criarLista();

    scanf("%d", &a.numero);
 
    if(a.numero != 0){
        while(a.numero != 0){    

        inserirFinalLista(lista, a);
        scanf("%d", &a.numero);
        }

        tipoNo *aux = lista->ult;
        mostraListaInvertida(lista, aux);
    }

    


    return 0;
}