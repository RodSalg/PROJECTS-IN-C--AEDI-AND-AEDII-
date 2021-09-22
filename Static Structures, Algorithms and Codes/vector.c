#include <stdio.h>
#include <stdlib.h>

void sign_vector(int *vet[], int tam){
    for(int i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }
}

void priint_vector(int vet[], int tam){

    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

}

int main(){

    int tam;
    scanf("%d", &tam);

    int vet[tam];
    sign_vector(vet, tam);
    priint_vector(vet, tam);


}