#include <stdlib.h>   /* malloc, free, exit */
#include <stdio.h>    /* printf */
#include <math.h>     /* sqrt */
#include "tadP.h"

struct ponto {
  float x;
  float y;
  float z;
};


Ponto* cria (float x, float y, float z){

  Ponto* p = (Ponto*) malloc(sizeof(Ponto));
  if (p == NULL){
    printf("Sem memória suficiente!\n");
    exit(1);
  }
  p->x = x;
  p->y = y;
  p->z = z;

  return p;
}


void acessa (Ponto* p, float* x, float* y, float *z) {

  *x = p->x;
  *y = p->y;
  *z = p->z;
}


void atribui (Ponto* p, float x, float y, float z){

  p->x = x;
  p->y = y;
  p->z= z;
}

float distancia (Ponto* p1, Ponto* p2){

  float dx = p2->x - p1->x;
  float dy = p2->y - p1->y;
  float dz = p2->z - p1->z;

  return sqrt(dx*dx + dy*dy + dz*dz);
}

void libera (Ponto* p) {

  free(p);
}