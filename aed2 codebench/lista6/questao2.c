#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//logica: se eu vir um '(' empilhar
//se eu vir um ')' desempilhar;
// se a pilha tiver elemento significa que ela nao está vazia e portanto sobrou algum elemento;

typedef char TELEM;

typedef struct pilha{

    TELEM vetor[100];
    int topo;

}Tpilha;

Tpilha iniciarPilha(){
    
    Tpilha pilha;

    pilha.topo = -1; //quando colocar um sera 0 primeiro elemento do indice

    return pilha;
};

void push(Tpilha *pilha, TELEM item){

    if(pilha->topo < (100-1)){
        pilha->topo = pilha->topo + 1;
        pilha->vetor[pilha->topo] = item;
    }else{
        printf("ta cheio");
    }
}

TELEM pop(Tpilha *pilha){
    TELEM aux;

    if( (pilha->topo) > -1){
        aux = pilha->vetor[pilha->topo];
        pilha->topo = pilha->topo - 1;

        return aux;
    }


}


TELEM MostrarTopo(Tpilha *pilha){
    if((pilha->topo)>(-1)){

        return pilha->vetor[pilha->topo];

    }else{
        //return NULL;
    }
}


void verifica_expressao(char exp[]){

    Tpilha pilha = iniciarPilha();

    int tam = strlen(exp);

    for(int i = 0; i < tam ; i++){ //percorre toda a pilha procurando parenteses colchetes  e chaves abertos
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[' ){
            push(&pilha, exp[i]);
        }
   
        //agora vou retirar a quantidade que entrou

        if(MostrarTopo(&pilha) == '(' && exp[i] == ')'){ //achou e percorre e coloca se achar
            pop(&pilha);
        }else if(MostrarTopo(&pilha) != '(' && exp[i] == ')'){
            push(&pilha, exp[i]);
        }else if(MostrarTopo(&pilha) == '[' && exp[i] == ']'){ //colchete
            pop(&pilha);
        }else if(MostrarTopo(&pilha) != '[' && exp[i] == ']'){
            push(&pilha, exp[i]);
        }else if(MostrarTopo(&pilha) == '{' && exp[i] == '}'){ //colchete
            pop(&pilha);
        }else if(MostrarTopo(&pilha) != '{' && exp[i] == '}'){
            push(&pilha, exp[i]);
        }

        } //fim do for para eu nao me perder


        if(pilha.topo == -1){ //significa que nao ha elementos na pilha
            printf("SIM\n");
        }else{
            printf("NAO\n"); //ha elementos e por tanto a expressao deixou algum parentese, colchete ou chave faltando
        }
        

}


int main(){
    
    char condicao[4] = {'#','#','#'};
    char exp[100]; //= {'(',')'};

    int compara = strcmp(exp, condicao);    
    
    scanf("%s", exp);

    while(compara != 0){

        verifica_expressao(exp);
        scanf("%s", exp);
        compara = strcmp(exp, condicao);

    }
        


}
