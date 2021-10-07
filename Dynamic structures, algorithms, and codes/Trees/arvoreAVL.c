
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
    if (root != NULL){
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

int main(){

    TAVL *root = NULL;
    printf("Deseja mostrar o resultado enquanto insere?[y/n]\n");
    char op;
    scanf(" %c", &op);

    int escolha = 0;

    if (op == 'Y' || op == 'y'){

        printf("Informe a forma de percurso: \n1)Pre-Ordem\n2)Em-Ordem\n3)Pós-Ordem \n(Qualquer outro: cancela)\n");
        scanf("%d", &escolha);
    }

    printf("INSIRA OS NUMEROS(-1 finaliza as insercoes)\n");
    int num;
    while (scanf("%d", &num), num != -1){

        root = inserir(root, num);
        if (escolha != 0)
            imprimirArvore(root, escolha);

    }
    
    if (root != NULL){

        printf("Deseja mostrar o resultado?[y/n]\n");
        scanf(" %c", &op);

        if (op == 'Y' || op == 'y')
        {
            printf("Informe a forma de percurso: \n1)Pre-Ordem\n2)Em-Ordem\n3)Pós-Ordem \n(Qualquer outro: cancela)\n");
            int escolha;
            scanf("%d", &escolha);
            imprimirArvore(root, escolha);
        }
    }
    else
    {
        printf("ARVORE VAZIA!\n");
    }

    return 0;

}