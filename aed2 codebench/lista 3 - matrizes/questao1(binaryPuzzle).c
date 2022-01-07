#include <stdio.h>
#include <stdlib.h>

int **cria_mat(){
    int **mat;
    mat = malloc(6 * sizeof(int *));

    for(int i = 0; i < 6; i++){
        mat[i] = malloc(6 * sizeof(int));
    }

    return mat;
}


void preencher_mat(int **matrix){
    for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			scanf("%d", &matrix[i][j]);
        }
    }

}

void imprime(int **matrix){
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			printf("%d ", matrix[i][j]);
			}
		printf("\n");
		}
}


int substitui_obvio(int **matrix){
    int flag = 0;

    //verifica linhas
	for(int i = 0; i < 6; i++){
		for(int j = 1; j < 6; j++){
			if( matrix[i][j-1] == 1 && matrix[i][j+ 1] == 1 && matrix[i][j] == 2 ){               
                matrix[i][j] = 0;
                flag = 1;
            }
            
            if( matrix[i][j-1] == 0 && matrix[i][j+ 1] == 0 && matrix[i][j] == 2 ){
                matrix[i][j] = 1;
                flag = 1;
            }
		}
	}

    //verifica colunas
    for(int i = 1; i < 5; i++){
		for(int j = 0; j < 6; j++){
			if( matrix[i - 1][j] == 1 && matrix[i + 1][j] == 1 && matrix[i][j] == 2 ){            
                matrix[i][j] = 0;
                flag = 1;
            }

            if( matrix[i - 1][j] == 0 && matrix[i + 1][j] == 0 && matrix[i][j] == 2 ){     
                matrix[i][j] = 1;
                flag = 1;
            }
		}
	}

    return flag;

}


int compara_sequencia(int **matrix){
    int flag = 0;
    
    //verifica linha
    for(int i = 0; i < 6; i++){
		for(int j = 0; j < 4; j++){
			if( matrix[i][j] == 1 && matrix[i][j+ 1] == 1){               
                matrix[i][j+2] = 0;
                matrix[i][j-1] = 0;
                //printf("caso 3 1 altera posicao [%d] [%d]\n", i, j);
                flag = 1;
            }
            
            if( matrix[i][j] == 0 && matrix[i][j+ 1] == 0){               
                matrix[i][j+2] = 1;
                matrix[i][j-1] = 1;
                //printf("caso 3 2 altera posicao [%d] [%d]\n", i, j);
                flag = 1;
            }
        }
    }

    //verifica coluna
    for(int i = 0; i < 5; i++){
		for(int j = 0; j < 6; j++){
			if( matrix[i][j] == 1 && matrix[i + 1][j] == 1){   
                //printf("caso 4 1 altera  posicao [%d] [%d]\n", i, j);         
                if(i < 4){
                    matrix[i+2][j] = 0;
                } 
                if(i > 0){
                    matrix[i-1][j] = 0;
                }  
                flag = 1;
            }

            if( matrix[i][j] == 0 && matrix[i + 1][j] == 0){   
                //printf("caso 4 1 altera  posicao [%d] [%d]\n", i, j);  
                if(i < 4){
                    matrix[i+2][j] = 1;
                }       
                if(i > 0 ){
                    matrix[i-1][j] = 1;
                }
                flag = 1;
            }
		}
	}

    return flag;

}

void play(){
   

    int venceu_1;
    int venceu_2;
    int **mat;
    mat = cria_mat();
    preencher_mat(mat);

    while(venceu_1 != 0 && venceu_2 != 0){
        venceu_1 = substitui_obvio(mat);
        venceu_2 = compara_sequencia(mat);
    }

    

    imprime(mat);


}

int main(){


    play();



    return 0;

}











