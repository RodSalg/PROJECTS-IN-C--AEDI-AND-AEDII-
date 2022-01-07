    #include <stdio.h>
    #include <stdlib.h>
    /*
    //condicoes para lembrar:
    // * nenhuma lista pode ter tamanho acima de 15 e sao numeros smp positivos (nao precisa condicao para aultima)
    */

    typedef struct vetores{

        int *info; //ponteiro para um vetor de inteiros
        int tamanho; //tamanho da minha lista
    }Vetor;

    //funcoes para manipular a lista de vetor;

    int Tamanho_Lista(Vetor lista){
        return lista.tamanho;
    }

    Vetor cria_lista(int tam){

        Vetor Lista;
        Lista.info = (int*)malloc(tam * sizeof(int));
        Lista.tamanho = tam;    
        
        return Lista;
    }

    void insere_lista(Vetor lista){

        for(int i = 0; i < Tamanho_Lista(lista); i++){
            scanf("%d", &lista.info[i]);
        }

    }

    void Imprime_Lista(Vetor lista){

        for(int i = 0; i < Tamanho_Lista(lista); i++){
            printf("%d ", lista.info[i]);
        }
        printf("\n");

    }

    Vetor concatena(Vetor Lista, Vetor Lista2, Vetor listaFinal){

        int tamanho = Tamanho_Lista(Lista) + Tamanho_Lista(Lista2);
        
        for( int i = 0; i < Tamanho_Lista(Lista); i++){
            listaFinal.info[i] = Lista.info[i];
        }
        int cont = 0;
        for( int i = ( tamanho -  Tamanho_Lista(Lista2)); i < tamanho; i++){
            listaFinal.info[i] = Lista2.info[cont];
            cont = cont + 1;
        }

        
            
        return listaFinal;
    }

int limpaListaVetor(Vetor *listaVetor){
    if(listaVetor->info != NULL){
        free(listaVetor->info);
        listaVetor->tamanho = 0;
        return 1; //Operação concluída
    }
    return 0; //A lista não está inicializada
}


    int main(){

        int n;
        scanf("%d", &n);
        if(n <= 15){
            Vetor vet = cria_lista(n);
            insere_lista(vet);
            
            scanf("%d", &n);
            if( n <= 15){
                Vetor vet2 = cria_lista(n);
                insere_lista(vet2);

                Vetor vetConc = cria_lista(Tamanho_Lista(vet) + Tamanho_Lista(vet2));
                vetConc = concatena(vet, vet2, vetConc);
                Imprime_Lista(vetConc);
            }           

        }

    }