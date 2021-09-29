#include <stdio.h>
#include <stdlib.h>

struct item{

    int num;

};
typedef struct item Item;

struct node{

    Item item;
    struct node *left;
    struct node *right;

};
typedef struct node Node;


// funcoes


Node *treeinitialize(){

    return NULL;
}


Item itemCreate(int cod){ //essa funcao simplifica a parte de adicionar um elemento ao item

    Item item;
    item.num = cod;

    return item;
}


//COMO FUNCIONA ARVORE BINARIA DE BUSCA:
// Ela se organiza indo para esquerda o menor elemento em comparação com a raíz da arvore ou subárvore;
// e indo para direita o elemento maior que a arvore ou subarvore;

Node *treeInsert(Node *root, Item x){ //fazendo de uma forma mais abstrata

 //quais sao os casos?


    //1° caso: não há elemento na raíz
    if( root == NULL){

        Node *aux = (Node*)malloc(sizeof(Node)); //aloco memoria para um nó
        //printf("sou a raiz [%d]\n", x.num);


        aux->item = x;
        aux->left = treeinitialize();
        aux->right = treeinitialize();

        return aux; //retorno o no que eu adicionei;

    }else{ //caso o nó nao seja nula ( ARVORE BINARIA DE BUSCA )

        if(x.num > root->item.num){ //se o numero for maior vai entrar na direita

            root->right = treeInsert(root->right, x);
           //printf("fui para a direita [%d]\n", x.num);

        }else if(x.num < root->item.num){   //caso o numero seja menor ele vai entrar na esquerda

            root->left = treeInsert(root->left, x);
            //printf("fui para a esquerda [%d]\n", x.num);
        }

    }

    return root;

}

//imprimir a arvore


void treePrint(Node *root){

    //sempre verificar se é vazia ou nao
    if(root){

        
        treePrint(root->left);
        printf("%d\n", root->item.num);
        treePrint(root->right);
       
        
    }

}

void treeFree(Node *root){

    //sempre verificar se é vazia ou nao
    if(root){
        
        treeFree(root->left);
        treeFree(root->right);
        free(root);
    }

}


//procurando algo na arvore

Node *treeSearch(Node *root, int cod){

    if(root){
         if(root->item.num == cod){
             return root;
         }else{
             if(cod > root->item.num){
                 return treeSearch(root->right, cod);
             }else{
                 return treeSearch(root->left, cod);
             }
         }
    }

    return NULL;

}

Node *treeMin(Node *root){
    if(root){
        Node *aux = root;
        while(aux->left != NULL){
            aux = aux->left;
        }
        return aux;
    }
    return NULL;
}


Node *treeRemove(Node *root, int cod){

     if(root){

         if(cod > root->item.num){
             root->right = treeRemove(root->right, cod);
         }else if(cod <  root->item.num){
             root->left = treeRemove(root->left, cod);
         }else{
             /// é igual encontrei o elemento que quero remover

             if(root->left == NULL && root->right == NULL){

                 free(root);
                 return NULL;

             }else if(root->left == NULL && root->right != NULL){
                 Node *aux = root->right; //um auxiliar que salva o elemento que vai ser retornado fazendo uma ponte
                 free(root);

                 return aux;
             }else if(root->left != NULL && root->right ==  NULL){
                 
                Node *aux = root->left;
                free(root);
                return aux;
            }else{
                Node *aux =  treeMin(root->right);
                Item itemAux = aux->item;
                root = treeRemove(root, itemAux.num);
                root->item = itemAux;
                
            }   
        }
        return root;
    }
    return NULL;   
}



Node *enxerta(Node *root, int cod, Node *SubRoot){

     if(root){

         if(cod > root->item.num){
             root->right = enxerta(root->right, cod, SubRoot);
         }else if(cod <  root->item.num){
             root->left = enxerta(root->left, cod, SubRoot);
         }else{
             /// é igual encontrei o elemento que quero remover

             if(root->left == NULL && root->right == NULL){

                if(SubRoot->item.num > root->item.num){
                    root->right = SubRoot;
                }else if(SubRoot->item.num < root->item.num){
                    root->left = SubRoot;
                }
                

             }  
        }
        return root;
    }

    return root;
      
}



int main(){

    Node *root = treeinitialize(); //raíz é nula;
    Node *rootAux = treeinitialize(); //raíz é nula;

    
    int numero;
    scanf("%d", &numero);
    while(numero != 0){

        root = treeInsert(root, itemCreate(numero)); 
        scanf("%d", &numero);

    }   

     
    scanf("%d", &numero);
    while(numero != 0){

        rootAux = treeInsert(rootAux, itemCreate(numero)); 
        scanf("%d", &numero);

    }

    scanf("%d", &numero);
    enxerta(root, numero ,rootAux);

    treePrint(root);

    treeFree(root);

    return 0;



}