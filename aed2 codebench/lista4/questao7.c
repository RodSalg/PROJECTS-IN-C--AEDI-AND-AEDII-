#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int negativo(int a);
int soma(int x, int b,int cont);



bool zero(int x){
    if(x == 0 ){
        return true;
    }

    return false; 
}

int incr(int x){
    return x + 1;
}

int decr(int x){
    return x - 1;
}

void preenche(int *vet, int tam, int aux){

    if(tam == 0){
        scanf("%d", &vet[aux]);
        //printf("chegamos ao fim\n");
    }else{
        //printf("meu tamanhao: %d\n", tam);
        tam = decr(tam);
        scanf("%d", &vet[aux]);
        //printf("meu aux: %d\n", aux);
        aux = incr(aux);
        
        return preenche(vet, tam, aux);
    }


}

void mostra(int *vet, int tam, int aux){ //percorre o meu vetor

    if(tam == 0){
        printf("%d ", vet[aux]);
    }else{
        tam = decr(tam);
        printf("%d ", vet[aux]);
        aux = incr(aux);
        
        return mostra(vet, tam, aux);
    }

}

int soma_vetor(int *vet, int tam, int aux, int resultado){ //percorre o meu vetor
    int aux2 = 0;
    //printf("meu tamanho antes de entrar: %d\n", tam);
    //printf("meu aux antes de entrar: %d\n", aux);
    if(tam ==0){
        resultado = soma(resultado, vet[aux], aux2);
        //printf("meu resutaldo final = %d\n", resultado);
        return resultado;
    }else{
        tam = decr(tam);
        //printf("%d ", vet[aux]);
        resultado = soma(resultado, vet[aux], aux2);
        //printf("meu resutaldo = %d\n", resultado);
        aux = incr(aux);
        
        return soma_vetor(vet, tam, aux, resultado);
    }

}

int soma(int x, int b,int cont){


    if(x == 0){
        b = b + cont;
        return b;
    }else{
        if(x < 0){
            x = incr(x);
            cont = decr(cont);
            
        }else{
            x = decr(x);
            cont = incr(cont);
        }
        
        return soma(x, b, cont);


    }

}


int negativo(int a){
  if (a<0) {return true;}
  else {return false;}
}


int main(){

    int n;
    int aux = 0;
	scanf("%d", &n);
    int vetor[n];
    n = n-1;
    int resulta = 0;
    preenche(vetor, n, aux);
    resulta = soma_vetor(vetor, n, aux, resulta);

    printf("%d", resulta);

    
}
