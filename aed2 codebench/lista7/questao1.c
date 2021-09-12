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

tipoAluno removerLista(tipoLista *l){ //retira o primeiro   

    tipoNo *aux;
    tipoAluno dado;

    aux = l->prim;
    l->prim = l->prim->prox;
    dado = aux->info;

    free(aux);

    return dado;
}





void jogo(tipoLista *lista){
    
    tipoLista *descartados;
    descartados = criarLista();
    
    int tras;
    int desc;
    tipoAluno a;
    tipoAluno b;
    while(lista->prim != lista->ult){
        desc = lista->prim->info.numero;
        b.numero = desc;
        removerLista(lista);
        inserirFinalLista(descartados, b);

        tras = lista->prim->info.numero;
        a.numero = tras;
        removerLista(lista);
        inserirFinalLista(lista, a);
        printf("\n");
        

    }
    printf("restou: ");
    mostrarLista(*lista);

    printf("descartadas: ");
    mostrarLista(*descartados);


}







int main(){

    
    tipoLista *lista;
    tipoAluno a;
    
    lista = criarLista();
    int tam;
    scanf("%d", &tam);
    for(int i = 1; i <= 3; i++){
        a.numero = i;
        inserirFinalLista(lista, a);
    }

    jogo(lista);

    


    return 0;
}