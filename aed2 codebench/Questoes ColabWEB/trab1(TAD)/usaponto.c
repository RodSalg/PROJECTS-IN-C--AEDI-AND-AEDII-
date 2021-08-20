#include <stdio.h>
#include "tadP.h"


int main () {

  Ponto *p1, *p2;
  float d;
  float x, y, z; //estou usando para guardar os dados do ponto 1 que sera alterado;
  float x1, y1, z1; //usarei para scanf dos dados do ponto 1;
  float x2, y2, z2; //usarei para scanf dos dados do ponto 2;

  scanf("%f %f %f", &x1, &y1, &z1);
 
    while(x1 != 0 && y1!= 0 & z1 != 0){
        p1 = cria(x1, y1, z1);
        acessa(p1, &x, &y, &z); //aqui guardo informações do meu primeiro ponto 1;

        //novas informações para o novo ponto1;
        scanf("%f %f %f", &x1, &y1, &z1);
        atribui(p1, x1, y1, z1);

        //introduzindo o ponto2;
        scanf("%f %f %f", &x2, &y2, &z2); 
        p2 = cria (x2, y2, z2);

        d = distancia (p1, p2);
        printf("%.2f\n", d);
        scanf("%f %f %f", &x1, &y1, &z1);
    }

    libera(p1);
    libera(p2);

    //end
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