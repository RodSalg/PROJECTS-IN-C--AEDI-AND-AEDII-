#include <stdio.h>
#include <stdlib.h>


void maiorElemento(int *v, int n, int *maior){

    *maior = v[0];
    for(int i = 0; i < n; i++){
        if(*maior <= v[i+1]){
            *maior = v[i+1];
        }
    }
}

int main(){

    int *ma;
    int a;
    scanf("%d", &a);
    while(a < 1 || a > 100){
        scanf("%d", &a);
    }


    int vetor[a];

    for(int i = 0; i < a; i++){
        scanf("%d", &vetor[i]);
    }


    maiorElemento(vetor, a, ma);
    printf("%d", *ma);

}
