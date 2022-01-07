#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void funcao(int a);
void repete(int a);



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

int simetrico(int x, int cont){


    if(x == 0){

        return cont;
    }else{
        if(x < 0){
            x = incr(x);
            cont = incr(cont);
            
        }else{
            x = decr(x);
            cont = decr(cont);
        }
        
        return simetrico(x, cont);


    }

}

void funcao(int a){
    int aux = 0;
    a = simetrico(a, aux);
    printf("%d\n", a);
	
    scanf("%d", &a);
	 repete(a);	

            
}

void repete(int a){

    if( a == 0){
        exit(1);
    }else{
        return funcao(a);
    }
}



int main(){

    int a;
	scanf("%d", &a);

	repete(a);	


    
}
