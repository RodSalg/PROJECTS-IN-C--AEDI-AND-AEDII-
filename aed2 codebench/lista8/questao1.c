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

ArvGen *insere(ArvGen *pai, ArvGen *filho)
{ //estou sempre inserindo no inicio, preciso de inserir no final
    //pai = c filho = D
    /*printf("quanto vale o meu pai = %c\n\n", pai->info );
    printf("quanto vale o meu filho = %c\n\n", filho->info );
    printf("\n\n >>>>>> entrei na funcao insere <<<<<< \n");*/
    //para inserir no inicio
    /*f->prox = a->prim;
    a->prim = f; */

    //para inserir no final

    ArvGen *aux;
    //printf("fiz ate aqui\n");
    if (pai->prim == NULL)
    { //verificar se é vazio
        //printf("\to primeiro do pai eh nulo vou alocar no lugar del e\n");
        pai->prim = filho;
        filho->prox = NULL;
        filho->prim = NULL;
        return filho;
    }
    else
    { //caso contrario significa que a lista possui pelo menos um elemento
        aux = pai->prim;
        //printf("\t existe pelo menos um elemento\n");

        while (aux)
        {
            if (aux->prox == NULL)
            {
                //printf("\t o proximo vai ser nulo, o proximo vai se tornar o filho\n");
                aux->prox = filho;
                //printf("\t esse e o meu aux.prox = %c\n", aux->prox->info);
                filho->prim = NULL;
                filho->prox = NULL;
                return filho;
            }
            else if (aux->prox != NULL)
            {
                //printf("\t vou saltar para procurar o proximo que sera nulo\n");
                aux = aux->prox;
            }
        }

        return NULL;
    }

    //printf("\n >>>>>> saida da funcao insere <<<<<< \n");
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

ArvGen *achaPai(ArvGen *pai, char code)
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
            {                           //forma de percorrer uma arvore generica através de recursão
                aux = achaPai(p, code); //guardando no auxiliar;
                if (aux != NULL)
                {
                    return aux; //caso exista ele vai retornar o aux como resposta;
                }
            }
        }
        return achaPai(pai->prox, code);
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
        pai = achaPai(aux, raizAuxChar);

        if (pai == NULL)
        {
            printf("\n o pai eh nulo\n");
            break;
        }

        /*printf("\n\n ***** debugando: ******\n");
        printf("esse e meu pai: %c", pai->info);
        printf("esse e meu filho: %c", novo->info);*/

        insere(pai, novo);
        /*printf(">>>>> minha arvore: \n");
        imprime(raiz);
        printf("fim da arvore <<<<<<<\n");*/

        //condicao de parada
        scanf(" %c", &novoChar);    //filho -> b
        scanf(" %c", &raizAuxChar); //pai -> a
        if (novoChar == '#' && raizAuxChar == '#')
        {
            flag = 1;
        }
    }

    imprime(raiz);
}
