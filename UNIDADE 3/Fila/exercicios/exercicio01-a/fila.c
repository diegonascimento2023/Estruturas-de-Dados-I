#include "fila.h"
typedef struct _fila
{
    int ini, fim;
    int qtde;     // num de elementos da fila
    int MAX_SIZE; // tamanho maximo da fila
    int *val;     // vetor dos valores
} Fila;

// Função para criar fila
Fila *CriaFila(int MAX_SIZE)
{
    Fila *Q = (Fila *)calloc(1, sizeof(Fila));

    Q->val = (int *)calloc(MAX_SIZE, sizeof(int));
    Q->MAX_SIZE = MAX_SIZE;
    Q->qtde = 0;
    Q->ini = Q->fim = 0;

    return Q;
}

// Função para destruir fila
void DestruirFila(Fila **Q)
{
    Fila *Qaux = *Q;
    free(Qaux->val);
    free(Qaux);

    *Q = NULL;
}

// Função para criar uma fila vazia
int FilaVazia(Fila *Q)
{
    return (Q->qtde == 0);
}

// Função para criar uma fila cheia
int FilaCheia(Fila *Q)
{
    return (Q->qtde == Q->MAX_SIZE);
}

// Função para inserir elemento na fila
int InsereFila(Fila *Q, int elem)
{
    if (FilaCheia(Q))
    {
        printf("Warning: Fila esta cheia\n");
        return 0; // Falha na inserçao
    }
    else
    {
        Q->val[Q->fim] = elem;
        Q->fim = (Q->fim + 1) % Q->MAX_SIZE;
        Q->qtde++;
        return 1; // sucesso na inserçao
    }
}

// Função para remover elemento da fila
int RemoveFila(Fila *Q, int elem)
{
    if (FilaVazia(Q))
    {
        printf("Warning: Fila esta vazia\n");
        return 0; // Falha na remoçao
    }
    else
    {
        Q->ini = (Q->ini + 1) % Q->MAX_SIZE;
        Q->qtde--;
        return 1; // sucesso na remoçao
    }
}

// Função para consutar fila
int ConsultaFila(Fila *Q, int *elem)
{
    if (FilaVazia(Q))
    {
        printf("Warning: Fila esta vazia\n");
        return 0; // Falha ao consultar a fila
    }
    else
    {
        *elem = Q->val[Q->ini];
        return 1; // sucesso ao consultar a fila
    }
}