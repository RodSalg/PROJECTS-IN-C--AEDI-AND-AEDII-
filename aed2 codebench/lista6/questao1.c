#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structs

typedef struct no{
    float valor;
    struct no *proximo;
}No;

//funcoes da pilha

No* push(No *pilha, float num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
    }
    else
        printf("no enought memory! ");
    return NULL;
}

No* pop(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("*");
    return remover;
}

//funcoes para funcao

float operacao(float a, float b, char x){ //identifica as operacoes
    switch(x){
    case '#':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;
    default: //caso padrao caso retorne nada
        return 0.0;
    }
}

float resolver_expressao(char x[]){
    char *pt;
    float num;
    No *n1, *n2, *pilha = NULL;

    pt = strtok(x, " "); // quebrar a string
    while(pt){
        if(pt[0] == '#' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
			  
            n1 = pop(&pilha);
            n2 = pop(&pilha);
            num = operacao(n2->valor, n1->valor, pt[0]);
            pilha = push(pilha, num);
            free(n1);
            free(n2);
        }
        else{
            num = strtol(pt, NULL, 10); //converter para numero
            pilha = push(pilha, num); //adicionar novamente na pilha o numero
        }
        pt = strtok(NULL, " ");
    }
    n1 = pop(&pilha);
    num = n1->valor;
    free(n1);
    return num;
}

int main(){

    char expressao[100];
    int tam;
    scanf("%d", &tam);

    for(int i = 0; i < tam; i++){
        
        scanf("%[^'.']%*c", expressao);
        printf("%.2f\n", resolver_expressao(expressao));
    }
    
}