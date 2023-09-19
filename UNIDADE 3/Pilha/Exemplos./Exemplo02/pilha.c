
/*
Listas encadeadas são estruturas de dados que permitem armazenar uma coleção
 de elementos de um mesmo tipo.

Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
*/

#include "pilha.h"
#include "lista.c"


struct pilha{
    Lista* prim;
};

// função que cria uma lista vazia (NULL)
Pilha *pilha_cria(void)
{
    Pilha* p= (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
	return p ;// Retorna p
}

// função que insere um elemento no início da pilha
void pilha_push(Pilha* p, int v)
{
	Lista* n= (Lista*) malloc(sizeof(Lista));
	n->info = v;
	n->prox = p->prim;
	p->prim = n;
}

// função que verifica se a pilha está vazia
int pilha_vazia(Pilha* p)//Recebe como parâmetro o endereço da pilha a ser verificada
{
	return (p->prim == NULL);//Retorna a pilha recebida com parâmetro vazia
}

// função que remove um elemento no início da pilha
int pilha_pop(Pilha* p){
    Lista* t;
    int v;
    if ( pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit (1);
    }
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}

// função que imprime pilha
void pilha_imprime(Pilha* p)
{
	lst_imprime(p->prim);
}


void pilha_libera(Pilha* p){
	lst_libera(p->prim);
    free(p);
}





