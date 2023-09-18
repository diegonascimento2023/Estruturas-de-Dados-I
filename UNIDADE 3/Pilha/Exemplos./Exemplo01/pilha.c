#include "pilha.h"

#define N 50 /*número máximo de elementos*/

struct pilha{
    int n;
    float vet[N];
};

Pilha* pilha_cria(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

void pilha_push(Pilha* p, float v){
    if(p->n == N){/* capacidade esgotada*/
        printf("Capacidade de pilha estourou.\n");
        exit(1);/* aborta programa*/
    }

    /* insere elemento na próxima posição livre */
    p->vet[p->n] = v;
    p->n++; /*p->: topo da pilha*/
}

int pilha_vazia(Pilha* p){
    return (p->n == 0);
}

float pilha_pop(Pilha* p){
    float v;
    if(pilha_vazia(p)){
      printf("Pilha vazia.\n");
        exit(1);/* aborta programa*/  
    }

    /* retira elemento do topo*/
    v = p->vet[p->n-1];
    p->n--;
    return v;
}

void pilha_libera(Pilha* p){
    free(p);
}

// função que imprime os elementos da pilha
void pilha_imprime(Pilha *p)//Recebe como parâmetro o endereço da pilha a ser impressa. Assim como, p representa a pilha a ser impressa.
{
	int i;//Criada a variável i do tipo lista para ser o contador do laço.
	for (i = p->n-1 ; i >= 0; i--)
	{
		printf("\tElemento: %f \n",  p->vet[i]);//Exibe o elemento presente no endereço armazenado em p->n-1.
	}
}