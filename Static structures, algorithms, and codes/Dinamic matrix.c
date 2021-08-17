#include <stdio.h>
#include <stdlib.h>

/* note: that is the first way to create a dinamyc matrix, i ll post the others */

int **create_matrix(int **mat, int row, int column){

    mat = malloc(row * sizeof(int *));

    for(int i = 0; i < row; i++){
        mat[i] = malloc(column * sizeof(int));
    }

    return mat;
}

void show_matrix(int **matrix, int l, int c){
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			printf("[%d] ", matrix[i][j]);
			}
		printf("\n");
		}
}

void assign_matrix(int **matrix, int row, int column){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			scanf("%d", &matrix[i][j]);
        }
    }		
}



int main(){

    int row;
    int column;

    scanf("%d", &row);
    scanf("%d", &column);
    
    int **matrixA = create_matrix(matrixA, row, column);

    assign_matrix(matrixA, row, column);
	//printf("\n\n\n");
	show_matrix(matrixA, row, column);


}