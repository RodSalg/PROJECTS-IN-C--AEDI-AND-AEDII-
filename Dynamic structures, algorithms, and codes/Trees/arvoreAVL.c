#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct avl TAVL;
struct avl
{

    int chave;
    TAVL *esq;
    TAVL *dir;
};

TAVL *criar_no(int valor)
{
    TAVL *no = (TAVL *)malloc(sizeof(TAVL));
    no->chave = valor;
    no->esq = NULL;
    no->dir = NULL;

    return no;
}

//obter a "altura" da árvore é o mesmo de pegar o maior caminho até o fim do nó
int altura(TAVL *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (altura(root->esq) > altura(root->dir))
            return altura(root->esq) + 1;
        else
            return altura(root->dir) + 1;
    }
}

//forma de obter o fator de balanceamento (FB)
int get_fb(TAVL *no_arvore)
{

    if (no_arvore != NULL)
        return (altura(no_arvore->esq) - altura(no_arvore->dir));
    else
        return 0;
}

//rotacionar para esquerda
TAVL *rot_esq(TAVL *root)
{
    TAVL *Aux = root->dir;
    root->dir = Aux->esq;
    Aux->esq = root;

    return Aux;
}

//rotacionar para direita
TAVL *rot_dir(TAVL *root)
{

    TAVL *Aux = root->esq;
    root->esq = Aux->dir;
    Aux->dir = root;

    return Aux;
}

// inserir na árvore AVL de forma recursiva
TAVL *inserir(TAVL *root, int chave)
{
    if (root == NULL)
    {
        root = criar_no(chave);
        return root;
    }
    else if (chave < root->chave)
        root->esq = inserir(root->esq, chave);
    else if (chave > root->chave)
        root->dir = inserir(root->dir, chave);

    int fb = get_fb(root);
    //as rotações dependem do fb e do valor da chave

    //rot simples para direita
    if (fb > 1 && chave < root->esq->chave)
        return rot_dir(root);

    //rot simples para esquerda
    if (fb < -1 && chave > root->dir->chave)
        return rot_esq(root);

    //rot dupla para direita
    if (fb > 1 && chave > root->esq->chave)
    {
        root->esq = rot_esq(root->esq);
        return rot_dir(root);
    }
    //rot dupla para esquerda
    if (fb < -1 && chave < root->dir->chave)
    {
        root->dir = rot_dir(root->dir);
        return rot_esq(root);
    }

    return root;
}

void imprimirPreOrdem(TAVL *root)
{
    if (root != NULL)
    {
        printf("%d ", root->chave);
        imprimirPreOrdem(root->esq);
        imprimirPreOrdem(root->dir);
    }
}

void imprimirEmOrdem(TAVL *root)
{
    if (root != NULL)
    {
        imprimirEmOrdem(root->esq);
        printf("%d ", root->chave);
        imprimirEmOrdem(root->dir);
    }
}

void imprimirPosOrdem(TAVL *root)
{
    if (root != NULL)
    {
        imprimirPosOrdem(root->esq);
        imprimirPosOrdem(root->dir);
        printf("%d ", root->chave);
    }
}

void imprimirArvore(TAVL *root, int tipo)
{

    if (root != NULL)
    {

        if (tipo == 1)
        {
            imprimirPreOrdem(root);
        }
        else if (tipo == 2)
        {
            imprimirEmOrdem(root);
        }
        else if (tipo == 3)
        {
            imprimirPosOrdem(root);
        }
    }
    printf("\n");
}

TAVL *menorvalor(TAVL *raiz)
{
    if (raiz->dir == NULL)
        return raiz;
    else
        return menorvalor(raiz->dir);
}

TAVL *menorvalorALT(TAVL *raiz)
{
    if (raiz->esq == NULL)
        return raiz;
    else
        return menorvalor(raiz->esq);
}

TAVL *busca(TAVL *root, int code, TAVL *aux)
{

    if (root) //nao e null
    {

        if (root->chave == code)
        {

            //printf("\nachei o [%d]\n", root->chave);
            return root;
        }
        else
        {

            if (aux != NULL)
            {
                //printf("\nestou retornando meu auxiliardasdasda\n");
                return aux;
            }
            aux = busca(root->esq, code, aux);
            aux = busca(root->dir, code, aux);
        }
    }
    //printf("\nestou retornando meu auxiliar\n");
    return aux;
}

TAVL *procuraMenor(TAVL *atual)
{

    TAVL *no1 = atual;
    TAVL *no2 = atual->dir;
    while (no2 != NULL)
    {
        no1 = no2;
        no2 = no2->esq;
    }

    return no1;
}

TAVL *treeRemove(TAVL *root, int cod)
{
    if (root)
    {

        if (cod > root->chave)
        {
            root->dir = treeRemove(root->dir, cod);
        }
        else if (cod < root->chave)
        {
            root->esq = treeRemove(root->esq, cod);
        }
        else
        {
            /// é igual encontrei o elemento que quero remover

            if (root->esq == NULL && root->dir == NULL)
            {

                free(root);
                return NULL;
            }
            else if (root->esq == NULL && root->dir != NULL)
            {

                TAVL *aux = root->dir; //um auxiliar que salva o elemento que vai ser retornado fazendo uma ponte
                free(root);

                return aux;
            }
            else if (root->esq != NULL && root->dir == NULL)
            {

                TAVL *aux = root->esq;
                free(root);
                return aux;
            }
            else
            {
                TAVL *aux = menorvalor(root->esq);

                int itemAux = aux->chave;
                root = treeRemove(root, itemAux);
                root->chave = itemAux;
            }
        }
        return root;
    }
    return NULL;
}

int busca_diferenca(TAVL *root)
{
    if ((get_fb(root)) > 1 || (get_fb(root)) < -1)
    {
        //printf("achei eh o %d\n", root->chave);

        return 1;
    }
    if (root->esq != NULL)
    {
        busca_diferenca(root->esq);
    }

    if (root->dir != NULL)
    {
        busca_diferenca(root->dir);
    }
    //return 0;
}

TAVL *balance(TAVL *root)
{

    if (root == NULL)
    {
        return root;
    }

    //para rotacoes a esquerda
    if ((get_fb(root)) < -1) //signfica que ele vai para a esquerda
    {
        //printf("entrei no primeiro caso\n");
        if ((altura(root->dir->esq)) <= (altura(root->dir->dir))) //rotacao simples
        {
            //printf("primeiro do primeiro\n");
            //printf("esse e meu root %d\n", root->chave);
            root = rot_esq(root);
            //printf("esse e meu root %d\n", root->chave);
            return root;
        }
        else
        { //rotacao dupla
            //printf("snadas\n");
            root->dir = rot_dir(root->dir);
            root = rot_esq(root);
            return root;
        }
    }

    //rotacoes para a direita
    if ((get_fb(root) > 1))
    {
        //printf("entrei aqui22\n");
        if ((altura(root->esq->dir)) <= (altura(root->esq->esq)))
        {
            //printf("entrei aqui33\n");
            root = rot_dir(root);
            return root;
        }
        else
        {
            //printf("entrei aqui445\n");
            //printf("entrei no segundo caso\n");
            root->esq = rot_esq(root->esq);
            root = rot_dir(root);
            return root;
        }
    }

    //printf("buscando no %d\n", root->chave);
    if (root->esq != NULL)
    {
        root->esq = balance(root->esq);
    }

    if (root->dir != NULL)
    {
        root->dir = balance(root->dir);
    }

    return root;
    //printf("\ncheguei ao fim\n");
}

TAVL *removeAVL(TAVL *root, int chave)
{

    root = treeRemove(root, chave);
    int a;
    a = busca_diferenca(root);
    if (root)
    {

        while (a == 1)
        {
            a = 0;
            root = balance(root);
            a = busca_diferenca(root);
        }
    }

    return root;
}
int main()
{

    TAVL *root = NULL;

    int num;
    scanf("%d", &num);
    while (num != 0)
    {
        root = inserir(root, num);
        scanf("%d", &num);
    }

    int *v; //definindo o ponteiro v
    int i, num_componentes = 100;
    int val;
    int cont = 0;

    v = (int *)malloc(num_componentes * sizeof(int));

    //Armazenando os dados em um vetor
    for (i = 0; i < num_componentes; i++)
    {
        scanf("%d", &val);
        if (val == 0)
        {
            i = num_componentes;
            break;
        }
        cont++;
        v[i] = val;
    }

    v = realloc(v, cont * sizeof(int));
    imprimirArvore(root, 2);
    printf("%d %d\n", altura(root) - 1, root->chave);

    for (i = 0; i < cont; i++)
    {
        TAVL *aux = NULL;
        if ((busca(root, v[i], aux)) != NULL)
        {
            root = removeAVL(root, v[i]);
            if (root)
            {
                imprimirArvore(root, 2);
                //printf("to tentando imprimir");
                printf("%d %d\n", altura(root) - 1, root->chave);
            }
        }
    }

    //printf("fim");
}
