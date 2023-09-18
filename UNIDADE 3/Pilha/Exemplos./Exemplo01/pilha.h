#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pilha Pilha;

/* Função para criar pilha.*/
Pilha* pilha_cria(void);

/* Função que insere um elemento na pilha.*/
void pilha_push(Pilha* p, float v);

/* Função para retirar o elemento do topo da pilha. */
float pilha_pop(Pilha* p);

/* Função para verificar se a pilha está vazia.*/
int pilha_vazia(Pilha* p);

/* Função para liberar pilha. */
void pilha_libera(Pilha*p);

/* Função que imprime os elementos da pilha. */
void pilha_imprime(Pilha *p);