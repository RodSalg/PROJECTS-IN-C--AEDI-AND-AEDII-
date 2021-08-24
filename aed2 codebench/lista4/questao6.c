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

int incrementa_n(int a, int cont){
    //antes de entrar o cont é igual ao A
    if(cont == 0){
        return a;
    }else{
        if(a < 0){
            a =decr(a);
            cont = incr(cont);
        }else{
            a = incr(a);
            cont = decr(cont);
        }      

        return incrementa_n(a, cont);
    }
}

int multiplica(int x, int b,int cont){

    //printf("o x no inicio da funcao eh: %d\n",x);
    //printf("o b no inicio da funcao eh: %d\n",b);

    if(b == 1){
        //printf("o x final  eh: %d\n",x);
        return x;
    }else{

        //printf("o x eh: %d\n", x);
        x = incrementa_n(x, cont);
        
        b = decr(b);
        //printf("o b eh: %d\n",b);

        return multiplica(x, b, cont);
    }

}

void funcao(int a, int b){
    if(b < 0 && a > 0){
        b = b * - 1;
        a = a * - 1;
    }
    int aux = a;
    a = multiplica(a, b, aux);
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
