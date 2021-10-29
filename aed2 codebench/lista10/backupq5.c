#include <stdio.h>
#include <stdlib.h>

// a tabela funciona agora vou aperfeiçoar para utilizar na q1
//

// constante que representa o tamanho da tabela
//#define M 99
typedef struct
{

    int matricula;

} Pessoa;

// inicializa a tabela com esse valor porque  saberei que posição está preenchida ou nao
void inicializarTabela(Pessoa tabelaHash[], int M)
{
    int i;
    for (i = 0; i < M; i++)
    {
        tabelaHash[i].matricula = -1; // marcamos através da matrícula
    }
}

// funcao de espalhamento
// vai receber a matrícula e gerar um código para salvar o elemento pessoa

int gerarCodigoHash(int chave, int M)
{   
    /*int a;
    a = chave % M;
    printf("\n\n meu retorno:%d %% %d = %d\n",chave, M, a);*/
    return chave % M; // recebe a chave e retorna o resto da divisao da chave por M;
}

// inserir uma pessoa na tabela;
void inserir(Pessoa tabelaHash[], int mat, int M)
{
    Pessoa pes;
    pes.matricula = mat;

    int indice = gerarCodigoHash(pes.matricula, M);
    while (tabelaHash[indice].matricula != -1)
    {
        indice = gerarCodigoHash(indice + 1, M);
    }
    tabelaHash[indice] = pes;
}

Pessoa *buscar(Pessoa tabelaHash[], int chave, int M)
{
    int cont = 0;
    int indice = gerarCodigoHash(chave, M);
    while (tabelaHash[indice].matricula != -1)
    {
        if (tabelaHash[indice].matricula == chave)
        {
            printf("SIM\n");
            return &tabelaHash[indice];
        }
        else
        {
            // printf("loop >>%d\n\n\n", indice);
            indice = gerarCodigoHash(indice + 1, M);
        }
        cont++;
        if (cont > M)
        {
            break;
        }
    }
    printf("NAO\n");
    return NULL;
}

void imprimir(Pessoa tabelaHash[], int M)
{
    int i;
    for (i = 0; i < M; i++)
    {
        if (tabelaHash[i].matricula != -1)
        {
            printf("%d %d\n", i, tabelaHash[i].matricula);
        }
        else
        {
            printf("%d \\\n", i);
        }
    }
}

int remover_hash(Pessoa *tabelaHash, int chave, int M)
{
    //primeiro vou buscar e verificar se o elemento existe na tabela hash;
    int cont = 0;
    int indiceOriginal;
    int indice = gerarCodigoHash(chave, M);
    while (tabelaHash[indice].matricula != -1)
    {
        if (tabelaHash[indice].matricula == chave)
        {
            //printf("excluindo o elemento %d na posicao %d\n", tabelaHash[indice].matricula, indice);
            //indiceFinal = indice;
            tabelaHash[indice].matricula = -1; //o elemento  é excluído
            break;
        }
        else
        {
            // printf("loop >>%d\n\n\n", indice);
            indice = gerarCodigoHash(indice + 1, M);
        }
        cont++;
        if (cont > M)
        {
            //printf("o elemento nao está aqui\n");
            return 0;
        }
    }
    indiceOriginal = indice; //esse se mantem
     // esse precisa rodar //esse precisa rodar
    //printf("to aqui  meu indice original %d  e meu indice posterior%d\n", indiceOriginal, indice);
    //agora preciso rearranjar a lista, mas como?

    int original;
    indice = gerarCodigoHash(tabelaHash[indice + 1].matricula, M);
    original = gerarCodigoHash(tabelaHash[indice].matricula, M); //novo indice
    
    while(tabelaHash)
    {
       
        //printf("to aqui  meu indice original %d  e meu indice que eh %d e o valor do elemento eh %d\n", indiceOriginal, indice, tabelaHash[indice]);

        if (tabelaHash[indice].matricula == -1)
        {
            //printf("o proximo elemento eh nulo\n");
            return 1;
        }
        else if (original <= indiceOriginal)
        {
            //printf("\tachei o substituto\n");
            //printf("\tele eh o %d %d\n", indice, tabelaHash[indice].matricula);
            tabelaHash[indiceOriginal].matricula = tabelaHash[indice].matricula;
            tabelaHash[indice].matricula = -1;

            //return 1;
            indiceOriginal = indice;
            //indice = gerarCodigoHash(tabelaHash[indiceOriginal + 1].matricula, M);
            //printf("meu indice original: %d meu novo indice: %d \n", indiceOriginal, indice);
            //printf("\n\n>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<\n");
        }
        
        
        // printf("meu hash que vai ser gerado eh o %d %% %d \n", tabelaHash[indice].matricula, M);
        //printf("\t indice: %d M: %d original: %d\n", indice, M, original);
        indice = gerarCodigoHash(indice + 1, M); // esse precisa rodar
        //printf("\n\n MEU INDICE NOVO: %d \n\n", indice);
        original = gerarCodigoHash(tabelaHash[indice].matricula, M); // novo indice
        

    }

    

}


int main()
{

    int tam = 11;
    int n = 8;
    //scanf("%d", &tam);
    //scanf("%d", &n);
    int num;
    Pessoa tabelaHash[tam];
    inicializarTabela(tabelaHash, tam);
    
    /*for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        inserir(tabelaHash, num, tam);
    }*/

    /*inserir(tabelaHash, 1234, tam);
    inserir(tabelaHash, 3234, tam);
    inserir(tabelaHash, 1324, tam);
    inserir(tabelaHash, 3333, tam);
    inserir(tabelaHash, 3019, tam);
    inserir(tabelaHash, 2786, tam);
    inserir(tabelaHash, 2222, tam);
    inserir(tabelaHash, 2028, tam);*/

   
    remover_hash(tabelaHash, 3333, tam);
    remover_hash(tabelaHash, 3019, tam);

    imprimir(tabelaHash, tam);

    
    int proc;
    scanf("%d", &proc);
    int ele;

    for(int i = 0; i < proc; i++)
    {
        scanf("%d", &ele);
        buscar(tabelaHash,ele, tam);

    }
    
}