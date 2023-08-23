#ifndef ALUNO_H
#define ALUNO_H

#include "disciplina.h"

typedef struct aluno Aluno;

/*Funçao que aloca dinamicamente uma estrutura do tipo Aluno e retorna o seu endereço. Os campos 
nome e matricula devem ser fornecidos como parâmetros*/
Aluno* cria_aluno(char nome[], int matricula);

/* Função que matricula o aluno em uma disciplina, adicionando o ponteiro da  disciplina ao array de disciplinas do aluno */
void matricula_disciplina(Aluno *aluno, Disciplina *disciplina);

/* Função que libera o espaço alocado dinamicamente para a estrutura.*/
void exclui_aluno(Aluno* aluno);

#endif