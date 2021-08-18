#include <stdio.h>
#include <stdlib.h>


void menorElemento(int *v, int n, int *menor){

    *menor = v[0];
    for(int i = 0; i < n; i++){
        if(*menor >= v[i+1]){
            *menor = v[i+1];
        }
    }
}

int main(){

    int *me;
    int a;
    scanf("%d", &a);
    while(a < 1 || a > 100){
        scanf("%d", &a);
    }
    //printf("\n a: %d\n", a);

    int vetor[a];
    for(int i = 0; i < a; i++){
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i < a; i++){
        //printf("%d\n", vetor[i]);
    }

    menorElemento(vetor, a, me);
    printf("%d", *me);

}
