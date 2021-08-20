#include <stdio.h>
#include <stdlib.h>
// é necessario duas coisas para se ter uma função recursiva:
// 1 - um caso base
// 2 - uma recursivdade

void preenche(int *vet, int tam){

    for(int i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }    
}

int produtorio(int *vet, int tam){
    //qual seria meu caso base?
    //pegar uma copia do tamanho do vetor e decrementá-lo até que chegue a posição '0'
    
    if(tam == 0){ //caso base
 
        return vet[tam];
    }else{  

        return  vet[tam] * (produtorio(vet, tam -1)); //caso recursivo
    }

}

void produtorio_vetor(){

    int n;
    scanf("%d", &n);
    int array[n];
    preenche(array, n);

    printf("\n%d\n", produtorio(array, n - 1));

}

int main(){

    produtorio_vetor();

    return 0;

}