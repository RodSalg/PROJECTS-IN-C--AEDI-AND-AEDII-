#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int soma(int x, int b,int cont);

int negativo(int a){ //função do professor
  if (a<0){
    return true;
  }
  else {
    return false;
  }

}

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


char *transforma_minusculo(char palavra[], int tam, int aux){ //percorre o meu vetor

    if(tam == 0){
        return palavra;
    }else{
        tam = decr(tam);
        //coloque sua operação aqui
        palavra[aux] = tolower(palavra[aux]);
        aux = incr(aux);
        
        return transforma_minusculo(palavra, tam, aux);
    }

}

void palindromo(char palavra[], int tam, int aux){ //percorre o meu vetor

    printf("%c e %c\n", palavra[aux], palavra[tam]);
    printf("aux: %d\n", aux);
    printf("tam: %d\n", tam);
    printf("ESTOU BUGANDO\n");

    if(tam <= tam/2){
        printf("sim");
    }else{ 
        //coloque sua operação aqui
        if(palavra[aux] == palavra[tam] ){
            printf("entrei aqui\n");
            printf("aux: %d\n", aux);
            printf("tam: %d\n", tam);
            aux = incr(aux);
            tam = decr(tam);             
            return palindromo(palavra, tam, aux);
        }else{
            tam = 0;
            printf("nao");
            return palindromo(palavra, tam, aux);
        }

        printf("ESTOU BUGANDO\n");
        
    }
}


int main(){

    int tam;
    int aux = 0;
    char word[20];
    scanf("%s", word); 
    
    tam = strlen(word); //tamanho da minha palavra
    tam = tam -1;
    transforma_minusculo(word, tam, aux);
    //printf("%s", word);

    palindromo(word, tam, aux);
    

}
