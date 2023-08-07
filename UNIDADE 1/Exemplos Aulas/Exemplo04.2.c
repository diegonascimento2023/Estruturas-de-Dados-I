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
    Disciplina *disciplina;
} Aluno;

// typedef struct aluno Aluno
//  typedef: Permite renomear qualquer variavel.
// struct aluno var_aluno;
// aluno: tipo
// var_aluno
    Aluno * cadastra_aluno(void);
    void imprime(Aluno * var_aluno);

int main(void)
{
    Aluno * var_aluno = cadastra_aluno();
    imprime(var_aluno);
    

    free(var_aluno->disciplina);
    free(var_aluno);

    return 0;
}

Aluno * cadastra_aluno(void)
{

    Aluno * var_aluno = (Aluno *)malloc(sizeof(Aluno));
    if (var_aluno == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    else
    {
        printf("Alocacao realizada com sucesso!\n");
    }

    var_aluno->disciplina = (Disciplina *)malloc(2 * sizeof(Disciplina));

    printf("Digite o nome:\n ");
    scanf(" %[^\n]", var_aluno->nome);

    printf("Digite a idade:\n ");
    scanf("%d", &(*var_aluno).idade); // outra forma de direcionar utilizando o ponto.

    printf("Digite a matricula:\n ");
    scanf("%d", &var_aluno->matricula);

    printf("Digite o nome da disciplina 1:\n ");
    scanf(" %[^\n]", var_aluno->disciplina[0].nome);
    printf("Digite o nome da disciplina 2:\n ");
    scanf(" %[^\n]", var_aluno->disciplina[1].nome);

    printf("Digite a nota da discplina 1:\n ");
    scanf("%f", &var_aluno->disciplina[0].nota);
    printf("Digite a nota da discplina 2:\n ");
    scanf("%f", &var_aluno->disciplina[1].nota);

    return var_aluno;
}

void imprime(Aluno * var_aluno){
    
    printf("Os dados informados:\n Nome: %s \t Idade: %d \t Matricula: %d  \n Disciplina 1: %s \t Nota da disciplina 1: %.2f  \nDisciplina 2: %s \t Nota da disciplina 2: %.2f", var_aluno->nome, var_aluno->idade, var_aluno->matricula, var_aluno->disciplina[0].nome, var_aluno->disciplina[0].nota, var_aluno->disciplina[1].nome, var_aluno->disciplina[1].nota);

}