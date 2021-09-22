#include <stdio.h>
#include <stdlib.h>

void sign_vector(int *matrix[][3], int row, int columns){

    for(int i = 0; i < row; i++){
        for(int j = 0; j < columns; j++){
            scanf("%d", matrix[i][j]);
        }
    }

}

void priint_vector(int matrix[][3], int row, int columns){

    for(int i = 0; i < row; i++){
        for(int j = 0; j < columns; j++){
            printf("[%d]", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

int main(){

    int i;
    int j;
    scanf("%d", &i); //rows 
    scanf("%d", &j); //columns

    int matrix[i][j];
    sign_vector(matrix, i, j);
    priint_vector(matrix, i, j);


}