#include <stdio.h>
#include <stdlib.h>

// Declarando estrutura do tipo aluno
typedef struct aluno
{
    int mat;
    char nome[81], end[81], tel[21];

} Aluno;

void inicializa(int n, Aluno **tab)
{
    int i;
    for (i = 0; i < n; i++)
    {
        tab[i] = NULL;
    }
}

/* Funcao que recebe como parametro o endereco de uma estrutura do tipo Aluno
e preenche seus campos com valores fornecidos pelo usuario via teclado.*/
void preenche(int n, Aluno **tab, int i)
{
    if (i < 0 || i >= n)
    {
        printf("Indice fora do limite do vetor.\n");
        exit(1);
    }
    if (tab[i] == NULL)
    {
        tab[i] = (Aluno *)malloc(sizeof(Aluno));

        printf(" Entre com a matricula: ");
        scanf("%d", &tab[i]->mat);

        printf(" Entre com o nome: ");
        scanf(" %80[^\n]", &tab[i]->nome);

        printf(" Entre com o endereco: ");
        scanf(" %120[^\n]", &tab[i]->end);

        printf(" Entre com o telefone: ");
        scanf(" %20[^\n]", &tab[i]->tel);
    }
}

/* Funcao que recebe como parametro o endereco de uma estrutura do tipo Aluno
e retira seus campos.*/
void retira(int n, Aluno **tab, int i)
{
    if (i < 0 || i >= n)
    {
        printf("Indice fora do limite do vetor.\n");
        exit(1); /*aborta o progama*/
    }
    if (tab[i] == NULL)
    {
        free(tab[i]);
        tab[i] = NULL; /*indica que a posição não mais existe dado*/
    }
}

/* Funcao que recebe como parametro o endereco de uma estrutura do tipo Aluno
e imprime os valores dos seus campos.*/
void imprime(int n, Aluno **tab, int i)
{
    if (i < 0 || i >= n)
    {
        printf("Indice fora do limite do vetor.\n");
        exit(1); /*aborta o progama*/
    }
    if (tab[i] == NULL)
    {
        printf("Matricula: %d\n", tab[i]->mat);
        printf("Nome: %s\n", tab[i]->nome);
        printf("Endereco: %s\n", tab[i]->end);
        printf("Telefone: %s\n", tab[i]->tel);
    }
}

/* Funcao que recebe como parametro o endereco de uma estrutura do tipo Pessoa
e imprime todos os valores dos seus campos.*/
void imprime_tudo(int n, Aluno **tab)
{
    int i;
    for (i = 0; i < n; i++)
    {
        imprime(n, tab, i);
    }
}

/* Função main para testar todas as demais funções declaradas nos itens anteriores*/
int main(void)
{
    Aluno *tab[10];
    inicializa(10, tab);
    preenche(10, tab, 0);
    preenche(10, tab, 1);
    preenche(10, tab, 2);
    imprime_tudo(10, tab);
    retira(10, tab, 0);
    retira(10, tab, 1);
    retira(10, tab, 2);
    return 0;
}