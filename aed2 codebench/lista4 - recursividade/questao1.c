#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void funcao(int a, int b);
void repete(int a, int b);
bool verifica_positivo(int a, int b);

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

bool menor(int x, int y){

    if(zero(x)){
        if(zero(y)){
            return false; //significa que eles sao iguais ou o y alcançou zero primeiro e é menor
        }
        return true; //significa que o x alcançou zero primeiro
    }else if( zero(y)){
      return false;
      }else{
        x = decr(x);
        y = decr(y);

        return menor(x,y);
    }   
}

void funcao(int a, int b){
    if(menor(a, b)){
            printf("SIM\n");
            scanf("%d", &a);
            scanf("%d", &b);

        }else{
            printf("NAO\n");
            scanf("%d", &a);
            scanf("%d", &b);
         
        }
	
			if(verifica_positivo(a, b)){
				 repete(a, b);	
			}
            
}

void repete(int a, int b){

    if( a == 0 && b == 0){
        exit(1);
    }else{
        return funcao(a,b);
    }
}

bool verifica_positivo(int a, int b){
	if(a > 0 && b > 0){
		return true;
	}
	
	return false;
}
int main(){

    int a;
    int b;
	scanf("%d", &a);
	scanf("%d", &b);
	if(verifica_positivo(a,b)){		
		repete(a, b);	
	}


    
}