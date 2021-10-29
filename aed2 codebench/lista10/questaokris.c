#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dado{
	int mat;
	char nome[16];
	int original;
} tipoDados;

typedef struct hash{
	tipoDados dado;
} tipoHash;

typedef tipoHash* Hash;

int hash (int mat, int tam){
	return (mat%tam);
}

void insere(Hash tab[], tipoDados dado, int tam){
	int h = hash(dado.mat, tam);
	int i = h;
	dado.original = h;
	while (tab[h] != NULL) {
		if (tab[h]->dado.mat == dado.mat) break;
		h = (h+1) % tam;
		if(h == i) break;
	}
	if (tab[h] == NULL){
		tab[h] = (tipoHash*) malloc(sizeof(tipoHash));
		tab[h]->dado = dado;
	}
}

int busca (Hash tab[], int mat, int tam){
	int h = hash(mat, tam);
	int i = h;
	while (tab[h] != NULL) {
		if (tab[h]->dado.mat == mat) return 1;
		h = (h+1)%tam;
		if(h == i) break;
	}
	return 0;
}

void retira(Hash tab[], int mat, int tam){
	int h = hash(mat, tam);
	int j = -1;
	while (tab[h] != NULL) {
		if(tab[h]->dado.mat == mat){
			free(tab[h]);
			tab[h] = NULL;
			j = h;
		}else if(tab[h]->dado.original <= j){
			tab[j] = tab[h];
			tab[h] = NULL;
			j = h;
		}
		h = h+1;
		if(h == tam) break;
	}
}

void imprime(Hash tab[], int tam){
	for(int i=0; i<tam; i++){
		if(tab[i] != NULL){
			printf("%d %d %d\n", i, tab[i]->dado.mat, tab[i]->dado.original);
		}
		else{
			printf("%d %c\n", i, 92);
		}
	}
	printf("\n");
}

int main(){
	int tam, M, i;
	tipoDados dado;
	scanf("%d %d", &tam, &M);
	if(tam == 0) exit(1);
	Hash tab[tam];
	for(i=0; i<tam; i++) tab[i] = NULL;
	for(i=0; i<M; i++){
		scanf("%d", &dado.mat);
		scanf("%s%*c", dado.nome);
		insere(tab, dado, tam);
	}
	imprime(tab, tam);
	int num;
	scanf("%d", &M);
	for(i=0; i<M; i++){
		scanf("%d", &num);
		retira(tab, num, tam);
	}
	imprime(tab, tam);
	scanf("%d", &M);
	for(i=0; i<M; i++){
		scanf("%d", &num);
		if(busca(tab, num, tam)){
			printf("SIM\n");
		}
		else printf("NAO\n");
	}
    }