#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo tipoNo;

typedef struct tipoAluno
{
    int idade;
}tipoAluno;

typedef struct tipoNo
{
    tipoAluno info;
    tipoNo *prox;

}tipoNo;

typedef struct tipoFila
{
    tipoNo *prim;
    tipoNo *fim;

} tipoFila;

void mostrarInfo(tipoAluno a)
{
    printf("%d ", a.idade);
}

tipoFila *criarFila()
{
    tipoFila *f;
    f = malloc(sizeof(tipoFila));
    f->prim = NULL;
    f->fim = NULL;

    return f;
}

void inserirFila(tipoFila *f, int a)
{
    tipoNo* no;

    no = (tipoNo*) malloc(sizeof(tipoNo));
    no->info.idade = a;
    no->prox = NULL;

    if(f->prim == NULL)
        f->prim = no;
    else
        f->fim->prox = no;
    
    f->fim = no;
}

void mostrarFila(tipoFila f)
{
    while(f.prim)
    {
        mostrarInfo(f.prim->info);
        f.prim = f.prim->prox;
    }
}

tipoAluno retira(tipoFila *f)
{
    tipoNo *aux;
    tipoAluno dado;
    aux = f->prim;
    f->prim = f->prim->prox;

    /*if(f->prim == NULL)
        f->fim == NULL;*/
    
    dado = aux->info;
    free(aux);

    return dado;
}

int haElementos(tipoFila *f)
{
    if(f->prim == NULL)
        return 0;
    return 1;
}

int primeiroFila(tipoFila *f)
{
    return f->prim->info.idade;
}

int ULtimoFila(tipoFila *f)
{
    return f->fim->info.idade;
}

int main() 
{

    tipoFila *fila;
    fila = criarFila();

    inserirFila(fila, 1);
    inserirFila(fila, 2);
    inserirFila(fila, 3);

    mostrarFila(*fila);

    retira(fila);

    printf("\n");
    mostrarFila(*fila);


}