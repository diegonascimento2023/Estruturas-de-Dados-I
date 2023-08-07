// Programa que cadastra funcionarios

#include <stdio.h>
#include <stdlib.h>
// Passo 1- Definir a struct que representa o funcionario
typedef struct funcionario
{
    char nome[50];
    float salario;
    int idade;
    char cargo[30];

} Funcionario;

// Passo 1- Função que Cadastrastra funcionarios

Funcionario *cadastraFuncionario(int qnt_funcionarios)
{
    /* Função que cadastra funcionarios */

    // Declaração de vetor do tipo funcionario
    Funcionario *vetor_funcionarios = (Funcionario *)malloc(qnt_funcionarios * sizeof(vetor_funcionarios));
    if (vetor_funcionarios == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    else
    {
        printf("Alocacao realizada com sucesso!\n");
    }

    // Preenche o vetor funcionario
    int indice;
    for (indice = 0; indice < qnt_funcionarios; indice++)
    {
        printf("\n\tFuncionario %d\n ", indice + 1);

        printf("Digite o nome do Funcionario:\n ");
        scanf(" %[^\n]", vetor_funcionarios[indice].nome);

        printf("Digite o idade do Funcionario:\n ");
        scanf("%d", &vetor_funcionarios[indice].idade);

        printf("Digite o salario do Funcionario:\n ");
        scanf("%f", &vetor_funcionarios[indice].salario);

        printf("Digite o cargo do Funcionario:\n ");
        scanf("%s", vetor_funcionarios[indice].cargo);
    }
    return vetor_funcionarios;
}

// Passo 3 - Função que imprime os dados dos funcionarios cadastrados

void imprimeFuncionarios(Funcionario *vetor_funcionarios, int qnt_funcionarios)
{
    printf("\n\n\t DADOS DOS FUNCIONARIOS \n\n");
    int indice;
    for (indice = 0; indice < qnt_funcionarios; indice++)
    {
        printf("Nome: %s \t Idade: %d \t Salario: %.2f \t Cargo: %s\n ",
               vetor_funcionarios[indice].nome, vetor_funcionarios[indice].idade, vetor_funcionarios[indice].salario, vetor_funcionarios[indice].cargo);
    }
}

int main(void)
{
    int qnt_funcionarios;
    printf("Digite a quantidade de funcionarios a ser cadastrada no sistema.\n");
    scanf("%d", &qnt_funcionarios);

    Funcionario *vetor = cadastraFuncionario(qnt_funcionarios);

    imprimeFuncionarios(vetor, qnt_funcionarios);

    return 0;
}