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
typedef struct quadro
{

    char pais[15];
    int Mouro;
    int Mprata;
    int Mbronze;

} TQuadro;

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

    for (int i = 0; i < tam; i++)
    {
        printf("%s ", quadro[i].pais);
        printf("%d ", quadro[i].Mouro);
        printf("%d ", quadro[i].Mprata);
        printf("%d\n", quadro[i].Mbronze);
        /* printf("pais: %s\n", quadro[i].pais);
         printf("ouro: %d\n", quadro[i].Mouro);
         printf("prata: %d\n", quadro[i].Mprata);
         printf("bronze: %d\n\n", quadro[i].Mbronze);*/
    }
}

TQuadro *PreencheQuadro(TQuadro *quadro, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        // printf("pais: ", quadro[i].pais);
        scanf("%s", &quadro[i].pais);
        // printf("ouro: ", quadro[i].Mouro);
        scanf("%d", &quadro[i].Mouro);
        // printf("prata: ", quadro[i].Mprata);
        scanf("%d", &quadro[i].Mprata);
        // printf("bronze: ", quadro[i].Mbronze);
        scanf("%d", &quadro[i].Mbronze);
    }

    return quadro;
}

TQuadro *OrdenandoQuadro(TQuadro *quadro, int tam)
{
    int i;
    int j;
    int min;
    TQuadro aux;
    for (i = 0; i < (tam - 1); i++)
    {
        min = i;

        for (j = (i + 1); j < tam; j++)
        {
            if (quadro[j].Mouro == quadro[min].Mouro)
            {
                if (quadro[j].Mprata == quadro[min].Mprata)
                {
                    if (quadro[j].Mbronze == quadro[min].Mbronze)
                    {
                        // ordenar pelo nome
                        // printf("cheguei na ordenação por nome\n");
                        int compara;
                        compara = strcmp(quadro[j].pais, quadro[min].pais);
                        if(compara <= 0)
                        {
                            //printf("\ncomparando por nome\n");
                            min = j;
                        }
                    }
                    else
                    {
                        if (quadro[j].Mbronze > quadro[min].Mbronze)
                        {
                            min = j;
                            // printf("organizando por bronze\n");
                        }
                    }
                }
                else
                {
                    if (quadro[j].Mprata > quadro[min].Mprata)
                    {
                        min = j;
                        // printf("organizando por prata\n");
                    }
                }
            }
            else
            {
                if (quadro[j].Mouro > quadro[min].Mouro)
                {
                    min = j;
                    // printf("organizando por ouro\n");
                }
            }
        }
        if (i != min)
        {
            aux = quadro[i];
            quadro[i] = quadro[min];
            quadro[min] = aux;
        }
    }

    MostraQuadro(quadro, tam);
}

int main()
{

    int tam;
    scanf("%d", &tam);
    TQuadro *quadro;
    quadro = inicializaQuadro(tam);
    // MostraQuadro(quadro, tam);
    quadro = PreencheQuadro(quadro, tam);
    // printf("\n\n");
    // MostraQuadro(quadro, tam);
    // printf("\n\n");
    OrdenandoQuadro(quadro, tam);
}