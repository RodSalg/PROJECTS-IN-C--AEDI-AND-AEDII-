#include <stdio.h>
#include <stdlib.h>

int **cria_mat(int **mat, int linha, int coluna){

    mat = malloc(linha * sizeof(int *));

    for(int i = 0; i < linha; i++){
        mat[i] = malloc(coluna * sizeof(int));
    }

    return mat;

}

void soma_matriz(int **matrix_total, int **matrix1, int **matrix2, int l, int c){

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            matrix_total[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void imprime(int **matrix, int l, int c){
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			printf("%d ", matrix[i][j]);
			}
		printf("\n");
		}
}

void preencher(int **matrix, int linha, int coluna){
	for(int i = 0; i < linha; i++){
		for(int j = 0; j < coluna; j++){
			scanf("%d", &matrix[i][j]);
        }
    }		
}


int main(){

    int linha;
    int coluna;

    scanf("%d", &linha);
    scanf("%d", &coluna);
    while( linha < 1 || linha > 20 || coluna < 1 || coluna > 20){
		  //printf("preso no while");
        scanf("%d", &linha);
    	  scanf("%d", &coluna);
    }
	  
    int **matrixA = cria_mat(matrixA, linha, coluna);
    int **matrixB = cria_mat(matrixB, linha, coluna);
    int **matrixC = cria_mat(matrixC, linha, coluna);

    //percorrer e preencher a matrix;
    preencher(matrixA, linha, coluna);
	 preencher(matrixB, linha, coluna);

    soma_matriz(matrixC, matrixA, matrixB, linha, coluna);
	 imprime(matrixC, linha, coluna);


}