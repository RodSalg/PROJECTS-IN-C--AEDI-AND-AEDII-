
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct avl TAVL;
struct avl{

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
int get_fb(TAVL *no_arvore){

    if (no_arvore != NULL)
        return (altura(no_arvore->esq) - altura(no_arvore->dir));
    else
        return 0;

}

//rotacionar para esquerda
TAVL *rot_esq(TAVL *ponto)
{
    TAVL *Aux = ponto->dir;
    ponto->dir = Aux->esq;
    Aux->esq = ponto;

    return Aux;
}

//rotacionar para direita
TAVL *rot_dir(TAVL *ponto)
{

    TAVL *Aux = ponto->esq;
    ponto->esq = Aux->dir;
    Aux->dir = ponto;

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

    printf("\n");
}

TAVL *menorvalor(TAVL *raiz)
{
    if (raiz->esq == NULL)
        return raiz;
    else
        return menorvalor(raiz->esq);
}

void balanco(TAVL *p)
{
    printf("\n balanco 1\n ");
    TAVL *aux;
    /*//printf("p->esq = %d || p->dir = %d", altura(p->esq), altura(p->dir));
    if(p->esq == NULL){
        printf("\n olha meu chapa\n");
    }

    printf("\n%d\n", p->esq->chave);*/

    //int fb = altura(p->esq) - altura(p->dir);
    printf("altura p: %d", altura(p));
    int fb = altura(p);
    printf("altura p: %d", fb);
    printf("\nbalanco 2\n ");

    if (fb >= 2){
        printf("\nbalanco 3\n ");
        aux = p->esq;
        fb = altura(aux->esq) - altura(aux->dir);
        if (fb < 0)
            printf("\nbalanco 4\n ");
            rot_esq(p->esq);

        rot_dir(p);
    }
    else if (fb <= -2)
    {
        printf("\nbalanco 5\n ");
        aux = p->dir;
        fb = altura(aux->esq) - altura(aux->dir);
        if (fb > 0)
            printf("\nbalanco 6\n ");
            rot_dir(p->dir);

        rot_esq(p);
    }

    printf("\nbalanco 7\n ");
}

void exclusao(TAVL *raiz, int chave){
    printf("\n 1 \n");

    if (raiz == NULL)
        return;

    //se a chave a ser excluida for menor que a chave da raiz
    //então ele vai ser excluido na subarvore esquerda
    if (chave < raiz->chave){
        printf("\n 2 \n");
        exclusao(raiz->esq, chave);

    //se a chave a ser excluida for maior que a chave da raiz
    //então ele vai ser excluido na subarvore direita
    }else if (chave > raiz->chave){
        printf("\n 3 \n");
        exclusao(raiz->dir, chave);

    // se a chave for o mesmo da raiz então será deletado
    }else{
        printf("\n 4 \n");
        // nó com um ou nenhum filho
        if (raiz->esq == NULL){
            printf("\n 5 \n");
            TAVL *temp = raiz->dir;
            free(raiz);
            raiz = temp;
            return;
        }
        else if (raiz->dir == NULL){
            printf("\n 6 \n");

            TAVL *temp = raiz->esq;
            free(raiz);
            raiz = temp;
            return;

        }

        printf("\n 7 \n");
        // nó com dois filhos: pega o menor dos maiores
        TAVL *temp = menorvalor(raiz->dir);
        // copia a chave do menor dos maiores para a raiz
        raiz->chave = temp->chave;

        // exclui o menor dos maiores
        printf("\n 8 \n");
        exclusao(raiz->dir, temp->chave);
    }

    printf("\n 9 \n");


    printf("\n> %d <\n", raiz->chave);
    balanco(raiz);
}

int main(){

    TAVL *root = NULL;

    int num;

    while (scanf("%d", &num), num != 0){

        root = inserir(root, num);
    }


    if (root != NULL){
            

        imprimirArvore(root, 2);
        printf("%d %d", altura(root) - 1, root->chave);
        printf("\n");
        exclusao(root, 4);
        printf("\neu saí de tudo entao provavalmente eu buguei a arvore\n");
        imprimirArvore(root, 2);
    

    }else{

        printf("ARVORE VAZIA!\n");

    }

    printf("\n\nfim");
}


