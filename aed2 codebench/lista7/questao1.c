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
    printf("%d, ", a.numero);
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
    
    while(l.prim->prox != NULL){
        mostrarInfo(l.prim->info);
        l.prim = l.prim->prox;
    }

    printf("%d ", l.prim->info.numero);

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
    //printf("\antes de entrar no while: ");
    //mostrarLista(*lista);
    while(lista->prim != lista->ult){
        desc = lista->prim->info.numero;
        b.numero = desc;
        removerLista(lista);
        inserirFinalLista(descartados, b);

        tras = lista->prim->info.numero;
        a.numero = tras;
        removerLista(lista);
        inserirFinalLista(lista, a); 

    }

    printf("Descartadas: ");
    mostrarLista(*descartados);
    printf("\nRestou: ");
    mostrarLista(*lista);
    printf("\n");

    removerLista(lista);

}







int main(){

    
    tipoLista *lista;
    tipoAluno a;
    
    lista = criarLista();
    int tam;
    scanf("%d", &tam);

    while(tam != 0){

        if(tam == 1){
        printf("Descartadas: ");
        printf("\nRestou: 1");
        printf("\n");
        }else{
            for(int i = 1; i <= tam; i++){
            a.numero = i;
            inserirFinalLista(lista, a);
        }

        jogo(lista);

        }
        scanf("%d", &tam);

    }

    free(lista);

    
    return 0;
}
 