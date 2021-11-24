#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{

    char nome[30];
    char comportamento;

} Lista;

Lista *iniciaLista(int tam)
{
    Lista *l;
    l = (Lista *)malloc(tam * sizeof(Lista));

    // l->comportamento = 'n';
    // strcpy(l->nome, "NULL");

    return l;
}

void quickSortMainLIST(Lista *lista, int count);
void quickSortLIST(Lista *lista, int left, int right);

Lista *preencher(Lista *l, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        // printf("comportamento:");
        scanf("%c", &l[i].comportamento);
        scanf("%*c");
        // printf("nome:");
        fgets(l[i].nome, 20, stdin);
    }

    return l;
}

void mostrar(Lista *lista, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%s", lista[i].nome);
    }
}

void quickSort(Lista *lista, int start, int end)
{
    quickSort(lista, start, end);
}

void Partition(Lista *lista, int start, int end)
{
    int i;
    int j;
    Lista *x;
    char temp[30];

    i = start;
    j = end;
    x = lista[(start + end) / 2];

    do
    {
        while ((strcmp(lista[i].nome, x->nome) < 0)))
        {
            i++;
        }
        while ((strcmp(lista[j].nome, x->nome) > 0))
        {
            j--;
        }
        if (i <= j)
        {
            strcpy(temp, lista[i].nome);
            strcpy(lista[i].nome, lista[j].nome);
            strcpy(lista[j].nome, temp);
            i++;
            j--;
        }
    } while (i <= j);

    if (start < j)
    {
        Partition(lista, start, j);
    }
    if (i < end)
    {
        Partition(lista, i, end);
    }
}

void NumeroCriancas(Lista *l, int tam)
{

    int aux = 0;
    int aux2 = 0;

    for (int i = 0; i < tam; i++)
    {
        if (l[i].comportamento == '+')
        {
            aux++;
        }
        else
        {
            aux2++;
        }
    }

    printf("\nSe comportaram: %d | Nao se comportaram: %d", aux, aux2);
}

int main()
{
    int tam;
    scanf("%d", &tam);
    scanf("%*c");

    Lista *lista;
    lista = iniciaLista(tam);

    lista = preencher(lista, tam);
    tam = tam -1;
    quickSortMainLIST(lista, tam);
    quickSortMainLIST(lista, tam);
    mostrar(lista, tam);
    NumeroCriancas(lista, tam);

    // printf("\nfim");
}