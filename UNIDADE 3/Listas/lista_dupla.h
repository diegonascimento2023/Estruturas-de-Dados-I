#include <stdio.h>
#include <stdlib.h>


typedef struct lista2 Lista2;

// função que insere um elemento na lista
Lista2 *lst2_insere(Lista2 *l, int v);

// função que cria uma lista vazia (NULL)
Lista2 *lst2_cria(void);

// função que retira um elemento da lista
Lista2 *lst2_retira(Lista2 *l, int v);

// função que busca um elemento na lista
Lista2 *lst2_busca(int elemento, Lista2 *l);

// função que imprime os elementos da lista
void lst2_imprime(Lista2 *l);

// função que libera a memória alocada para a lista
void lst2_libera(Lista2 *l);