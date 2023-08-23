#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"

typedef struct aluno
{
    char nome[30];
    float nota;
} Aluno;

Aluno *aluno_cria(char *nome, float nota)
{
    Aluno *a = (Aluno *)malloc(sizeof(Aluno));
    if (a == NULL)
    {
        printf("Memoria insuficiente.\n");
    }

    strcpy(a->nome, nome);
    a->nota = nota;

    return (a);
}

void aluno_libera(Aluno *a)
{
    free(a);
}

void aluno_imprime(Aluno *a)
{
    printf("Dados aluno %p", a);
    printf("Nome do aluno: %[^\n]", a->nome);
    printf("Nota do aluno: %f", a->nota);
}

void aluno_ordena(int n, Aluno **v)
{
    Aluno *auxiliar = NULL;
    int i;
    for (i = 0; i < n; i++)
    {

        if (v[i]->nome[0] < v[i + 1]->nome[0])
        {
            auxiliar = v[i];
            v[i] = v[i + 1];
            v[i + 1] = v[i];
        }
    }
}

void aluno_salva(FILE *fp, int n, Aluno **v)
{

    // Abrir/criar o arquivo de saida para escrita (w)
    fp = fopen("saida_q3.txt", "w");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    int i;
    for (i = 0; i < n; i++)
    {

        fprintf(fp, "nome_do_aluno\tnota_do_aluno\n%s\t%f", v[i]->nome, v[i]->nota);
    }
}