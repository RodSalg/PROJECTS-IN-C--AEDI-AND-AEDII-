#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void funcao(int a, int b);
void repete(int a, int b);



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

void funcao(int a, int b){
    int aux = 0;
    a = soma(a, b, aux);
    printf("%d\n", a);
	
    scanf("%d", &a);
    scanf("%d", &b);
	 repete(a, b);	
            
}

void repete(int a, int b){

    if( a == 0 && b == 0){
        exit(1);
    }else{
        return funcao(a, b);
    }
}



int main(){

    int a;
    int b;
	scanf("%d", &a);
    scanf("%d", &b);

	repete(a, b);	


    
}
