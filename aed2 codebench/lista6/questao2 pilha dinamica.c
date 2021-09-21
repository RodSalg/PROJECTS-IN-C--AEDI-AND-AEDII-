#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//**************************************** STRUCTS *********************************************
//**********************************************************************************************
//**********************************************************************************************


typedef struct tipoDado{

	char equacao;

}tipoDado;


typedef struct tipoNo tipoNo;
typedef struct tipoNo{

	tipoDado info;
	tipoNo* prox;

}tipoNo;


typedef struct pilha{

	tipoNo* topo;
	int tam;

}Pilha;



//**************************************** FUNCTIONS *********************************************
//************************************************************************************************
//************************************************************************************************

Pilha *pilha_cria(){

	Pilha *l;
	l = malloc(sizeof(Pilha));
	l->topo = NULL;
	l->tam = -1;

    return l;

}

/*void pilha_push2(Pilha *l, char equa){

	tipoNo *no;
	no = (tipoNo*)malloc(sizeof(tipoNo));
    strcpy(no->info.equacao, equa);
	no->prox = l->topo;
	l->topo = no;
	l->tam++;


}*/

void pilha_push(Pilha *l, char equa){

	tipoNo *no;
	no = (tipoNo*)malloc(sizeof(tipoNo));
    no->info.equacao = equa;
	no->prox = l->topo;
	l->topo = no;
	l->tam++;


}


char pilha_pop(Pilha *l){

	tipoNo *aux;
	char dado;
	aux =l->topo;
	l->topo = l->topo->prox;
    dado = aux->info.equacao;
    l->tam--;
	free(aux);


	return dado;


}

int pilha_vazia(Pilha *l){

    if(l->topo == NULL){
        return 0;
    }else{
        return 1;
    }

}


void verifica_expressao(char exp[]){


    Pilha *pilha;
    pilha = pilha_cria();
    int tam = strlen(exp); //tamanho da equação
    int flag = 0;

    for(int i = 0; i < tam ; i++){ //percorre toda a pilha procurando parenteses colchetes  e chaves abertos
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[' ){
            //printf("\nentrei na funcao2\n");
            pilha_push(pilha, exp[i]);
        }

        //printf("\nentrei na funcao3\n");
        //printf("vou bugar hen");
        //printf("\nmeu tamanaho [%d]\n", pilha->tam);

        if(pilha->tam == -1 && ( exp[i] == '}' || exp[i] == ')' || exp[i] == ']'  )){
            printf("NAO");
            flag = 1;
        }else{
            if(pilha->topo->info.equacao == '(' && exp[i] == ')'){  //agora vou retirar a quantidade que entrou
                //achou e percorre e coloca se achar
                //printf("\n tirei da pilha\n");
                pilha_pop(pilha);
            }else if(pilha->topo->info.equacao != '(' && exp[i] == ')'){
                //printf("\n coloquei na pilha\n");
                pilha_push(pilha, exp[i]);
                
            }else if(pilha->topo->info.equacao == '[' && exp[i] == ']'){ //colchete
            
                pilha_pop(pilha);
                
            }else if(pilha->topo->info.equacao != '[' && exp[i] == ']'){
                ;
                pilha_push(pilha, exp[i]);
                
            }else if(pilha->topo->info.equacao == '{' && exp[i] == '}'){ //colchete
                
                pilha_pop(pilha);
            }else if(pilha->topo->info.equacao != '{' && exp[i] == '}'){
            
                pilha_push(pilha, exp[i]);
                
            }
        }
   
       
        


        //printf("\nfinal do for\n");

        

        } //fim do for para eu nao me perder



        //printf("consegui concluir");
        if(flag == 1){

        }else{
            if(pilha->tam == -1){ //significa que nao ha elementos na pilha
                printf("SIM\n");
            }else{
                printf("NAO\n"); //ha elementos e por tanto a expressao deixou algum parentese, colchete ou chave faltando
            }
        }

        

}




void pilha_libera(Pilha* p){

    while (p->topo != NULL) {
    tipoNo *pointer = p->topo;
    p->topo = p->topo->prox;
    free(pointer);
}
    free(p);

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








