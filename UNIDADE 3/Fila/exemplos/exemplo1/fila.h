#include <stdio.h>
#include <stdlib.h>

typedef struct _fila Fila;

// Função para criar fila
Fila *CriaFila(int MAX_SIZE);

// Função para destruir fila
void DestruirFila(Fila **Q);

// Função para criar uma fila vazia
int FilaVazia(Fila *Q);

// Função para criar uma fila cheia
int FilaCheia(Fila *Q);

// Função para inserir elemento na fila
int InsereFila(Fila *Q, int elem);

// Função para remover elemento da fila
int RemoveFila(Fila *Q, int elem);

// Função para consutar fila
int ConsultaFila(Fila *Q, int *elem);