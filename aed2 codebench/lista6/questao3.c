#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo tipoNo;

typedef struct tipoAviao{
    
    char linha[4];
    int numero;


}tipoAviao;

typedef struct tipoNo{
    tipoAviao info;
    tipoNo *prox;
} tipoNo;


typedef struct tipoFila{
    tipoNo *prim;
    tipoNo *fim;
    int tam;

}tipoFila;

void mostrarInfo(tipoAviao a){
    printf("%s %d \n", a.linha, a.numero);
    
}

tipoFila *criarlista(){
    tipoFila *l;
    l = malloc (sizeof(tipoFila));
    l->prim = NULL;
    l->fim = NULL;
    l->tam = -1;

    return l;
} 

void AdicionaAviao(tipoFila *l, tipoAviao a){
    tipoNo *no;
    no = (tipoNo*) malloc(sizeof(tipoNo));
    no->info = a;
    no->prox = NULL;

    if(l->prim == NULL){
        l->prim =no;
        l->tam = l->tam + 1;
    }else{
        l->fim->prox = no;
        l->tam = l->tam + 1;
    }
    l->fim = no;
}

void MostrarAvioes(tipoFila l){

    while(l.prim){

        mostrarInfo(l.prim->info);
        l.prim =l.prim->prox;
    }
    
}

tipoAviao DecolaAviao(tipoFila *l){

    tipoNo *aux;
    tipoAviao dado;

    aux = l->prim;
    l->prim = l->prim->prox;
    dado = aux->info;
    l->tam = l->tam - 1;

    free(aux);

    return dado;
}

//para essa questao trarei funcoes para que fique melhor encapsulado e nao tao confuso

void NumeroAvioes(tipoFila *pista){ //funcao para o Q

    printf("%d\n", pista->tam + 1);
}

void primeiroAviao(tipoFila *pista){ //retorna o primeiro aviao
    mostrarInfo(pista->prim->info);
}

void liberaPista(tipoFila *pista){
    free(pista);
}

void controlePista(){

    tipoFila *pista;
    pista = criarlista();
    tipoAviao a;

    char escolha;
    scanf("%c", &escolha);
    int infinite = 0;

    while(infinite == 0){ //loop infinito a saída é quebrada no caso S

        switch(escolha){
            case 'Q': //quantidade de avioes
                //printf("\nentrei no Q\n");
                NumeroAvioes(pista);
                break;
            case 'A': //quantidade de avioes
                //printf("\nentrei no A\n");
                scanf("%s", &a.linha);
                scanf("%d", &a.numero);     
                AdicionaAviao(pista, a);
                //printf("\nadicionei na pista\n");
                break;
            case 'D': //o primeiro aviao decola
                //printf("\nentrei no D\n");
                DecolaAviao(pista);
                break;
            case 'L':
                //printf("\nentrei no L\n");
                MostrarAvioes(*pista);
                break;
            case 'P':
               //printf("\nentrei no P\n");
                primeiroAviao(pista);
                break;
            case 'S':
                //printf("\nentrei no S\n");
                //printf("to fora");
                liberaPista(pista);
                //infinite = 1;
                exit(1);
                break;   
        }

        scanf("%c", &escolha);
        

    }



}



int main(){

    controlePista();


}