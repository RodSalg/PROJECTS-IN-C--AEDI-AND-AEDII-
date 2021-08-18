#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tadP.h"



int main(){

    printf("=)\n");
    float x;
    float y;
    float z;
    float x2;
    float y2;
    float z2;

    Ponto *ponto1 = cria();
    Ponto *ponto2 = cria();

    //primeira variavel
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &z);  
    
    while( x != 0 && y!= 0 & z != 0){

        atribui(ponto1, x, y, z);
        //segunda variavel
        scanf("%f", &x2);
        scanf("%f", &y2);
        scanf("%f", &z2);
        atribui(ponto1, x2, y2 , z2);
    
        //terceira variavel 
        scanf("%f", &x2);
        scanf("%f", &y2);
        scanf("%f", &z2);
        atribui(ponto2, x2, y2, z2);

        //impressão dos
        printf("%.2f %.2f %.2f\n", x, y, z);
        imprime(ponto1);
        imprime(ponto2);


        float total = distancia(ponto1, ponto2);
        printf("%.2f\n", total);
        

        //primeira variavel
        scanf("%f", &x);
        scanf("%f", &y);
        scanf("%f", &z);

        //printf("\n\n\n looping \n\n\n\n");


    }

    return 0;
}

/* caso teste: 
ENTRADA
-3 4 3
4 -8 -9
2 -3 -5
0 0 0

SAÍDA
-3 4 3
4 -8 -9
2 -3 -5
6.71

Sugestão do Luca: 

deixar os scanf mais clean através da seguinte função:

    void scan_geral(float *x, float *y, float *z){

        scanf("%f", x);
        scanf("%f", y);
        scanf("%f", z); 
    }



 */