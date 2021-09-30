#include <stdio.h>
#include <stdlib.h>

struct arvgen
{

    char info;
    struct arvgen *prim;
    struct arvgen *prox;
};

typedef struct arvgen ArvGen;

ArvGen *cria(char c)
{

    ArvGen *a = (ArvGen *)malloc(sizeof(ArvGen));

    a->info = c;
    a->prim = NULL;
    a->prox = NULL;

    return a;
}

void insereInicio(ArvGen *a, ArvGen *f)
{

    f->prox = a->prim;
    a->prim = f;
}

ArvGen *insere(ArvGen *pai, ArvGen *filho) //insere no final
{

    //para inserir no final

    ArvGen *aux;
   
    if (pai->prim == NULL){ //verificar se é vazio

        pai->prim = filho;
        filho->prox = NULL;
        filho->prim = NULL;

        return filho;
    }else{ //caso contrario significa que a lista possui pelo menos um elemento
        aux = pai->prim;
        

        while (aux){
            if (aux->prox == NULL){
               
                aux->prox = filho;
                filho->prim = NULL;
                filho->prox = NULL;
                return filho;
            }
            else if (aux->prox != NULL){
                aux = aux->prox;
            }
        }

        return NULL;
    }

}

void imprime(ArvGen *a)
{

    ArvGen *p;
    printf("%c\n", a->info);

    for (p = a->prim; p != NULL; p = p->prox)
    {
        imprime(p);
    }
}

void libera(ArvGen *a)
{

    ArvGen *p = a->prim;

    while (p != NULL)
    {

        ArvGen *t = p->prox;
        libera(p);
        p = t;
    }

    free(a);
}

ArvGen *busca(ArvGen *pai, char code)
{ //funcao de busca

    if (pai != NULL)
    { //verifica se o pai é nulo
        if (pai->info == code)
        {
            return pai;
        }
        else
        {
            ArvGen *p;   // ponteiro usado para percorrer a lista sem perder a lista original com o ponteiro original
            ArvGen *aux; //variavel que vai guardar o retorno caso encontre o valor

            for (p = pai->prim; p != NULL; p = p->prox)
            {                         //forma de percorrer uma arvore generica através de recursão
                aux = busca(p, code); //guardando no auxiliar;
                if (aux != NULL)
                {
                    return aux; //caso exista ele vai retornar o aux como resposta;
                }
            }
        }
        return busca(pai->prox, code);
    }

    return NULL;
}

int main()
{

    //agora eu preciso automatizar

    char raizChar;    //raiz principal
    char raizAuxChar; // raiz criada como folha da principal
    char novoChar;

    ArvGen *raiz;
    scanf(" %c%*[^\n]", &raizChar);
    raiz = cria(raizChar); //raiz principal

    ArvGen *raizAux;
    ArvGen *novo;
    ArvGen *pai;

    int flag = 0;

    scanf(" %c", &novoChar);    //filho -> b
    scanf(" %c", &raizAuxChar); //pai -> a

    if (novoChar == '#' && raizAuxChar == '#')
    {
        flag = 1;
    }

    while (flag == 0)
    {

        novo = cria(novoChar);

        ArvGen *aux;
        aux = raiz;
        pai = busca(aux, raizAuxChar);

        if (pai == NULL)
        {
            printf("\n o pai sempre deve existir\n");
            break;
        }

        insere(pai, novo);

        scanf(" %c", &novoChar);    //filho -> b
        scanf(" %c", &raizAuxChar); //pai -> a
        if (novoChar == '#' && raizAuxChar == '#')
        {
            flag = 1;
        }
    }

    imprime(raiz);
}
