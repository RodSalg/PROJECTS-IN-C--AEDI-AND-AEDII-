#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ESTRUTURAS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/*
    estrutura definida;
    criar um vetor de structs
    definir um tipo de estrutura com os 4 tipos de medalhas e o nome
    a estrutura possui o nome do país juntamente do numero de medalhas de ouro prata e bronze

*/
typedef struct quadro{

    char pais[15];
    int Mouro;
    int Mprata;
    int Mbronze;

}TQuadro;

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> FUNCOES DE MEDALHAS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
TQuadro *inicializaQuadro(int tam)
{

    TQuadro *m;
    m = (TQuadro *)malloc(tam * sizeof(TQuadro));

    for (int i = 0; i < tam; i++)
    {
        m[i].Mouro = 0;
        m[i].Mprata = 0;
        m[i].Mbronze = 0;
        strcpy(m[i].pais, "NULL");
    }

    return m;
}

void MostraQuadro(TQuadro *quadro, int tam)
{

    for (int i = 0; i < tam; i++){
        printf("pais: %s\n", quadro[i].pais);
        printf("ouro: %d\n", quadro[i].Mouro);
        printf("prata: %d\n", quadro[i].Mprata);
        printf("bronze: %d\n\n", quadro[i].Mbronze);
        
    }
}

TQuadro *PreencheQuadro(TQuadro *quadro, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("pais: ", quadro[i].pais);
        scanf("%s", &quadro[i].pais);
        printf("ouro: ", quadro[i].Mouro);
        scanf("%d", &quadro[i].Mouro);
        printf("prata: ", quadro[i].Mprata);
        scanf("%d", &quadro[i].Mprata);
        printf("bronze: ", quadro[i].Mbronze);
        scanf("%d", &quadro[i].Mbronze);
    }


    return quadro;
}

TQuadro *OrdenandoQuadro(TQuadro *quadro, int tam)
{
    int i, j, min, aux;
    for (i = 0; i < (tam - 1); i++)
    {
        min = i;
        for (j = (i + 1); j < tam; j++)
        {
            if (quadro[j].Mouro < quadro[min].Mouro)
                min = j;
        }
        if (i != min)
        {
            aux = num[i];
            num[i] = num[min];
            num[min] = aux;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf(" %d |", num[i]);
    }
}

TQuadro *selectionSort(int num[], int tam)
{
    int i, j, min, aux;
    for (i = 0; i < (tam - 1); i++)
    {
        min = i;
        for (j = (i + 1); j < tam; j++)
        {
            if (num[j] < num[min])
                min = j;
        }
        if (i != min)
        {
            aux = num[i];
            num[i] = num[min];
            num[min] = aux;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf(" %d |", num[i]);
    }
}

int main(){

    int tam = 8;
    TQuadro *quadro;
    quadro = inicializaQuadro(tam);
    MostraQuadro(quadro, tam);
    quadro = PreencheQuadro(quadro, tam);
    printf("\n\n");
    MostraQuadro(quadro, tam);
}