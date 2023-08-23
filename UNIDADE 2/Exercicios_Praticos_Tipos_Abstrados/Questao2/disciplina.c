#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "disciplina.h"

typedef struct disciplina
{
    char nome[30]; // armazena o nome da disciplina.
    int codigo; // armazena o código identificador único da disciplina.
    
} Disciplina;

Disciplina *criaDisciplina(char * nome, int codigo)
{
    Disciplina* disciplina = (Disciplina *)malloc(sizeof(Disciplina));
    if (disciplina == NULL)
    {
        printf("Memoria alocada com sucesso.");
        exit(1);
    }

    strcpy(disciplina->nome, nome);
    disciplina->codigo = codigo;

    return disciplina;
}


 void exclui_disciplina(Disciplina* disciplina)
{
    free(disciplina);
}