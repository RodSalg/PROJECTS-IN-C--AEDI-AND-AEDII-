#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int valor;
    char nome[80];
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
}Lista;

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}


// procedimento para inserir no fim
void inserir_no_fim(Lista *lista, int num, char novonome[]){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        strcpy(novo->nome, novonome);
        

        // é o primeiro?
        if(lista->inicio == NULL){
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
        }
        else{
            lista->fim->proximo = novo;
            lista->fim = novo;
            // as duas linhas a seguir são sinônimas. Escolha a que achar mais fácil compreender
            //lista->fim->proximo = lista->inicio;
            novo->proximo = lista->inicio;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}



// função para remover um nó
No* remover(Lista *lista, char string[]){
    No *teste, *aux, *remover = NULL;
    int compara;
    teste = lista->inicio;





        compara = strcmp(string, teste->nome);


    if(lista->inicio){
        if(lista->inicio == lista->fim){ //significa que possuo somente um elemento e nao preciso de comparacoes
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tam--;
          
        }
        else if((strcmp(string ,lista->inicio->nome)) == 0){ //significa que ele é o primeiro mas nao que a lista so possui um elemento
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tam--;
           
        }
        else {
            aux = lista->inicio;
    


            do{
                compara = strcmp(string, teste->proximo->nome);

                if(compara == 0){
                    break;
                }else{
             
                    teste = teste->proximo;
                }
                
        
            }while(teste->proximo != lista->inicio);

    

            if(compara == 0){
                if(lista->fim == teste->proximo){
                    remover = teste->proximo;
                    teste->proximo = remover->proximo;
                    lista->fim = teste;
                    
                }
                else{
                    remover = teste->proximo;
                    teste->proximo = remover->proximo;
                   
                }
                lista->tam--;
            }
            
        }

    }

    return remover;
}

// procedimento para imprimir a lista circular
void imprimir(Lista lista){
    No *no = lista.inicio;
    if(no){
        do{
            
            no = no->proximo;
        }while(no != lista.inicio);
    }
    printf("\n");
}



void Programa(Lista *l, int incr){
    //printf("\nentrei no programa\n");
    No *no = l->inicio;
    int tempo = 0; 

        do{
            
            //printf("\nantes do incremetnto: %d\n", no->valor);
            no->valor = no->valor - incr;
            //printf("depois do incremetnto: %d\n", no->valor);

            if(no->valor <= 0){

                //printf("\nantes do incremetnto depois que achoua condicao: [%d]\n", no->valor);
                no->valor = no->valor + incr;
                //printf("antes do incremetnto depois que achoua condicao: [%d]\n", no->valor);
                //printf("meu tempo antes: [%d]\n", tempo);
                tempo = tempo + no->valor;
                //printf("meu tempo depois: [%d]\n", tempo);
                printf("%d us: %s finalizou\n", tempo, no->nome);
                //int retira;
                //retira = no->valor;

                char retiraString[80];
                strcpy(retiraString, no->nome);

                no = no->proximo;
                remover(l, retiraString);
                

            }else{
                //printf("\n\n\n pulando \n\n\n");
                tempo = tempo + incr;
                no = no->proximo;
            }

        }while(l->inicio != NULL);



}

int main(){

    char letras[80];
    int valor;
    Lista lista;

    criar_lista(&lista);

    int quantidade;
    int tempo;

    scanf("%d", &tempo);
    scanf("%d", &quantidade);

    criar_lista(&lista);

    if(tempo > 0 && quantidade > 0){
        for(int i = 0; i < quantidade; i++){

            scanf("%s", letras);
            scanf("%d", &valor);

            if(valor > 0){
                inserir_no_fim(&lista, valor, letras);
            }
            
            

        }

        Programa(&lista, tempo);
    }


}



