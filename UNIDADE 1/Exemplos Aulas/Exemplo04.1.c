// Progama que manipula struct aluno
#include <stdio.h>
#include <stdlib.h>

typedef struct disciplina
{
    char nome[30];
    float nota;

} Disciplina;

typedef struct aluno
{
    char nome[20];
    int idade;
    int matricula;
    Disciplina disciplina;
} Aluno;

// typedef struct aluno Aluno
//  typedef: Permite renomear qualquer variavel.
// struct aluno var_aluno;
// aluno: tipo
// var_aluno

int main(void)
{
    Aluno *var_aluno = (Aluno *)malloc(sizeof(Aluno));
    if (var_aluno == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    else
    {
        printf("Alocacao realizada com sucesso!\n");
    }

    printf("Digite o nome:\n ");
    scanf(" %[^\n]", var_aluno->nome);

    printf("Digite a idade:\n ");
    scanf("%d", &(*var_aluno).idade); // outra forma de direcionar utilizando o ponto.

    printf("Digite a matricula:\n ");
    scanf("%d", &var_aluno->matricula);

    printf("Digite o nome da disciplina:\n ");
    scanf(" %[^\n]", var_aluno->disciplina.nome);

    printf("Digite a nota da discplina:\n ");
    scanf("%f", &var_aluno->disciplina.nota);

    printf("Os dados informados:\n Nome: %s \t Idade: %d \t Matricula: %d  \t Disciplina: %s \t Nota da disciplina: %.2f", var_aluno->nome, var_aluno->idade, var_aluno->matricula, var_aluno->disciplina.nome, var_aluno->disciplina.nota);

    free(var_aluno);

    return 0;
}