#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//**************************************** STRUCTS *********************************************
//**********************************************************************************************
//**********************************************************************************************

typedef struct tipoDado
{

    int numero;

} tipoDado;

typedef struct tipoNo tipoNo;
typedef struct tipoNo
{

    tipoDado info;
    tipoNo *prox;

} tipoNo;

typedef struct pilha
{

    tipoNo *topo;
    int tam;

} Pilha;

//**************************************** FUNCTIONS *********************************************
//************************************************************************************************
//************************************************************************************************

Pilha *pilha_cria()
{

    Pilha *l;
    l = malloc(sizeof(Pilha));
    l->topo = NULL;
    l->tam = -1;

    return l;
}


void pilha_push(Pilha *l, int num)
{

    tipoNo *no;
    no = (tipoNo *)malloc(sizeof(tipoNo));
    no->info.numero = num;
    no->prox = l->topo;
    l->topo = no;
    l->tam++;
}

int pilha_pop(Pilha *l)
{

    tipoNo *aux;
    int dado;
    aux = l->topo;
    l->topo = l->topo->prox;
    dado = aux->info.numero;
    l->tam--;
    free(aux);

    return dado;
}

int pilha_vazia(Pilha *l)
{

    if (l->topo == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int topo(Pilha *p)
{
    return p->topo->info.numero;

}



void pilha_libera(Pilha *p)
{

    while (p->topo != NULL)
    {
        tipoNo *pointer = p->topo;
        p->topo = p->topo->prox;
        free(pointer);
    }
    free(p);
}
void mostrarInfo(tipoDado p)
{
    printf("%d ", p.numero);
}
void MostrarPilha(Pilha p)
{ 

    while (p.topo != NULL)
    {
        mostrarInfo(p.topo->info);
        p.topo = p.topo->prox;
    }

    //printf("%d ", l.prim->info.numero);
}

int main()
{

    Pilha *stack;
    stack = pilha_cria();

    pilha_push(stack, 1);
    pilha_push(stack, 2);
    pilha_push(stack, 3);
    pilha_push(stack, 4);

    MostrarPilha(*stack);

    pilha_pop(stack);
    printf("\n");
    MostrarPilha(*stack);
}
