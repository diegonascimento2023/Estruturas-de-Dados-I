// Progama que manipula struct aluno
#include <stdio.h>

 typedef struct aluno
{ 
    char nome[20];
    int idade;
    int matricula;

}Aluno;
 
 //typedef struct aluno Aluno
 // typedef: Permite renomear qualquer variavel.
 //struct aluno var_aluno;
//aluno: tipo
//var_aluno

int main(void)
{
    struct aluno var_aluno;
    printf("Digite o nome:\n ");
    scanf(" %[^\n]", var_aluno.nome);

    printf("Digite a idade:\n ");
    scanf("%d", &var_aluno.idade);

    printf("Digite a matricula:\n ");
    scanf("%d", &var_aluno.matricula);

    printf(" Os dados informados:\n Nome: %s \t Idade: %d \t Matricula: %d ", var_aluno.nome, var_aluno.idade, var_aluno.matricula);

    return 0;
}
