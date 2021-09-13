#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo tipoNo;
typedef struct tipoDado{

    char nome[80];
    int numero;

}tipoDado;

typedef struct tipoNo{
    tipoDado info;
    tipoNo *prox;

}tipoNo;


typedef struct tipoLista{
    tipoNo* atual;

}tipoLista;


tipoLista* criarLista(){
    tipoLista *l;
    l = malloc(sizeof(tipoLista));
    l->atual = NULL;

    return l;

}

void mostrarInfo(tipoDado a){
    printf("%s %d \n",a.nome, a.numero);
}

void inserirLista(tipoLista *l, tipoDado a){ //insere no inicio da lista
    tipoNo* no;
    no = (tipoNo*)malloc(sizeof(tipoNo));
    no->info = a;

    if(l->atual){

        no->prox = l->atual->prox; 

    }else{

        l->atual = no;
    }
    l->atual->prox = no;

}

void mostrarLista(tipoLista *l){
    tipoNo *aux;
    if(l->atual){
        aux = l->atual;
        do{
            mostrarInfo(aux->info);
            aux = aux->prox;
        }while(aux != l->atual);
    }

}

int removerLista(tipoLista *l, int chave){
    tipoNo *aux, *ant;
    
    if(l->atual){
        aux = l->atual;
        do{
            ant = aux;
            aux = aux->prox;

            if(aux->info.numero == chave){
                if(ant == aux){
                    l->atual = NULL;
                }else{
                    ant->prox = aux->prox;
                    if(aux == l->atual){
                        l->atual = aux->prox;
                    }
                }
                free(aux);
                return 1;
            }

        }while(aux != l->atual);
    }   

    return 0; 
}


void contaTempo(tipoLista *lista, int tempo){

    
    int cont = 0;
    int vezes = 0;
    
    if(lista->atual){

        //percorrer com um auxiliar e retirar com o ponteiro da lista
        do{
            vezes++;
            //printf("meu tempo: %d\n\n", cont );
            //printf("valor do meu elemento %d\n", lista->atual->info.numero );
            lista->atual->info.numero = lista->atual->info.numero - tempo;
            //printf("valor do meu elemento pos subtracao %d\n", lista->atual->info.numero );




            if(lista->atual->info.numero > 0){



                cont = cont + tempo;
                if(lista->atual == NULL){
                    lista->atual = NULL;
                }else{
                    lista->atual = lista->atual->prox;
                }

                
            }else{ 

                //printf("%d", lista->atual->info.numero );
                //printf(" + %d\n", tempo);
                lista->atual->info.numero = lista->atual->info.numero + tempo;


                //printf("%d +", cont); 
                //printf(" %d\n", lista->atual->info.numero);
                cont = cont + lista->atual->info.numero; //meu tempo  
 

                printf("%d us: %s finalizou\n", cont, lista->atual->info.nome);
                removerLista(lista, lista->atual->info.numero);
                if(lista->atual != NULL){
                    lista->atual = lista->atual->prox;
                }
                
            }



            
            


        }while(lista->atual != NULL);

        //printf("eu saí do while");
    }   

}

int main(){

    
    tipoLista *lista;
    tipoDado a;
    
    lista = criarLista();
    int tempo;
    int quantidade;

    scanf("%d", &tempo);
    scanf("%d", &quantidade);

    if(tempo > 0 && quantidade > 0){
        for (int i = 0; i < quantidade; i++){
            
            scanf("%s", a.nome);
            scanf("%d", &a.numero);
            if(a.numero <1){
                while(a.numero < 1 ){
                inserirLista(lista, a);   
                }
            }else{
                inserirLista(lista, a);   
            }
            
                
            
        }

        
        contaTempo(lista, tempo);


    }






    return 0;
}