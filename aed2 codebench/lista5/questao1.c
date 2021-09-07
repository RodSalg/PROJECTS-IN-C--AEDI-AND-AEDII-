#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNo tipoNo;
typedef struct tipoAgenda{
    
    char nome[81];
    char endereco[81];
    float numero; //altura

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
    printf("nome: %s, endereco: %s, idade: %.2f\n", a.nome, a.endereco, a.numero);
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


void media(tipoLista l){
    
    int cont = 0;
    float acumulador;
    while(l.prim){

        acumulador = acumulador + l.prim->info.numero;
        cont = cont + 1;
        l.prim = l.prim->prox;
    }

    float media;
    media = acumulador/cont;
    printf("%.2f", media);
}

int lestring(char s[], int max)
{
    int i = 0;
    char letra;

    for (i = 0; i < (max - 1); i++) {
   letra = fgetc(stdin);

 
   if ((letra == '\n') && (i == 0)) {
       i = i - 1;
       continue;
   }


   if (letra == '\n')
       break;
   s[i] = letra;
    }
    s[i] = 0;

    return (i);
}



int main(){

    
    tipoLista *lista;
    tipoAgenda a;
    int tam;
    

    char teste[4] = "XXX";
    int compara;
    compara = strcmp(teste, a.nome);

    lista = criarLista();

    scanf("%[^\n]%*c", a.nome);
    compara = strcmp(teste, a.nome);
    int flag = 0;

    while(compara != 0){

        scanf("%[^\n]%*c", a.endereco);
        scanf("%f", &a.numero);

        inserirFinalLista(lista, a);

        scanf("%[^\n]%*c", a.nome);
        compara = strcmp(teste, a.nome);
        flag = 1;
    }


    mostrarLista(lista);
    printf("\n\n");
    
    if(flag == 1){
        media(*lista);
    }
    




    
    





    return 0;
}