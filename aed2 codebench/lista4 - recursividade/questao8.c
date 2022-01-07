#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int soma(int x, int b,int cont);

int negativo(int a){
  if (a<0) {return true;}
  else {return false;}
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

int **cria_matrix(int **mat, int linha, int coluna, int aux){

    if(linha == 0){
        return mat;
    }else{
        mat[aux] = malloc(coluna * sizeof(int));
        aux = incr(aux);
        linha = decr(linha);

        return cria_matrix(mat, linha, coluna, aux);
    }

}

int **preenche_matrix(int **mat, int linha, int coluna, int aux, int aux2){

    if(linha == 0){
        return mat;
    }else{
        //printf("linha: [%d] coluna:[%d]\n", aux, aux2);
        scanf("%d", &mat[aux][aux2]);
        //mat[aux][aux2]= aux + 1;
        //printf("\telemento [%d]\n\n", mat[aux][aux2]);
        if(aux2 == coluna -1){
            aux2 = 0;
            aux = incr(aux);
            linha = decr(linha);
            return preenche_matrix(mat, linha, coluna, aux, aux2);
        }
        aux2 = incr(aux2);
        
        return preenche_matrix(mat, linha, coluna, aux, aux2);
    }

}

int soma_matrix(int **mat, int linha, int coluna, int aux, int aux2, int resulta){
    //printf("entrei na soma matrix\n");
    int cont = 0;
    if(linha == 0){
        //printf(" ***************meu resulta eh: [%d]\n", resulta);
        return resulta;
    }else{
        resulta = soma(resulta, mat[aux][aux2], cont);
        //printf(" ***************meu resulta somando ainda eh: [%d]\n", resulta);
        if(aux2 == coluna -1){
            aux2 = 0;
            aux = incr(aux);
            linha = decr(linha);
            return soma_matrix(mat, linha, coluna, aux, aux2, resulta);
        }
        aux2 = incr(aux2);
        
        return soma_matrix(mat, linha, coluna, aux, aux2, resulta);
    }

}


int main(){

     
    int li;
    int col;
    int aux = 0;
    int aux2 =0;
    int resultado = 0;
    scanf("%d", &li);
    scanf("%d", &col);
    
    int **mat;
    mat = malloc(li * sizeof(int *));
    mat = cria_matrix(mat, li, col, aux); //agora temos uma matriz criada dinamicamente através de recursão

    //proximo passo é preencher toda a matrix
    preenche_matrix(mat, li, col, aux, aux2);
	//agora vamos somar os elementos
    resultado = soma_matrix(mat, li, col, aux, aux2, resultado);
    printf("%d", resultado);


        //printf( "feliz e triste");
}
