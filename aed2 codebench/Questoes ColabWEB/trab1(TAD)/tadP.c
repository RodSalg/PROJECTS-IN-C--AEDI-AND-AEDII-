#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tadP.h"


Ponto *cria(){
    Ponto *p = (Ponto*)malloc(sizeof(Ponto));


    return p;
}

void acessa(Ponto *p, float *x, float *y, float *z){

    *x = p->x;
    *y = p->y;
    *z = p->z;
}

void atribui(Ponto *p, float x, float y, float z){

    p->x = x;
    p->y = y;
    p->z = z;

}

float distancia(Ponto *p1, Ponto *p2){

    float dx;
    float dy;
    float dz;
    float total;

    dx = p2->x - p1->x;
    dy = p2->y - p1->y;
    dz = p2->z - p1->z;
    

    total = sqrt((dx * dx) + (dy * dy) + (dz * dz));

    return total;
}

void imprime(Ponto *ponto){

    printf("%.2f ", ponto->x);
    printf("%.2f ", ponto->y);
    printf("%.2f\n", ponto->z);
}

