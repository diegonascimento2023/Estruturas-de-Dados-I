/*Escreva um programa que implementa uma struct Aluno com os seguintes campos: nome, matrícula, curso e índice acadêmico. A variável índice acadêmico deve ser uma union que armazena um dos índices: índice geral (IG), índice de rendimento (IRA) acadêmico ou índice de rendimento técnico (IRT). O programa deve ler os dados de um aluno e imprimir os dados do aluno. COM ALOCAÇÃO DINÂMICA*/

#include <stdio.h>
#include <stdlib.h>

typedef union indice_a
{
    float IG, IRA, IRT;
} IA;

typedef struct aluno
{
    int mat;
    char nome[20];
    char curso[20];
    IA indice;
} Aluno;

int main(void)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    if (aluno == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    else
    {
        printf("Alocacao realizada com sucesso!\n");
    }

    IA indice;
    int op;

    printf("Digite o nome:\n ");
    scanf(" %[^\n]", aluno->nome);
    printf("Digite a matricula:\n ");
    scanf("%d", &aluno->mat);
    printf("Digite o curso:\n ");
    scanf(" %[^\n]", aluno->curso);

    printf("Digite: \n 0-IG \n 1-IRA \n 2-IRT\n");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        printf("Digite o IG:\n ");
        scanf("%f", &aluno->indice.IG);
        break;
    case 1:
        printf("Digite o IRA:\n ");
        scanf("%f", &aluno->indice.IRA);
        break;
    case 2:
        printf("Digite o IRT:\n ");
        scanf("%f", &aluno->indice.IRT);
        break;

    default:
        break;
    }

    printf("\n\t DADOS ALUNO\n Nome: %s\n Matricula %d\n Curso: %s\n Indice Academico: %.2f ", aluno->nome, aluno->mat, aluno->curso, aluno->indice.IG);
    free(aluno);
    return 0;
}
