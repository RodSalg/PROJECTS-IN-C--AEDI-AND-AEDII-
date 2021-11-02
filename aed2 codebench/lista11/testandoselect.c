#include <stdio.h>
#include <stdlib.h>

void selection_sort(int num[], int tam)
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

int main()
{

    int  vector[5];

    vector[0] = 4;
    vector[1] = 6;
    vector[2] = 8;
    vector[3] = 2;
    vector[4] = 3;

    for (int i = 0; i < 5; i++)
    {
        printf(" %d |", vector[i]);
    }

    printf("\n");

    selection_sort(vector, 5);
}