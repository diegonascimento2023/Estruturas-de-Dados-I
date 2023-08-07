/*1. Crie um tipo estruturado para armazenar dados de um funcionario. Uma estrutura deste tipo possui
os seguintes campos: nome, salario, identificador e cargo.
a) Escreva uma funcao que receba como parametro o endereco de uma estrutura do tipo Funcionario
e preencha seus campos com valores fornecidos pelo usuario via teclado.
b) Escreva uma funcao que receba como parametro o endereco de uma estrutura do tipo Funcionario
e imprima os valores dos seus campos.
c) Implemente uma funcao para realizar uma alteracao no salario de uma estrutura do tipo Funcionario.
d) Escreva uma funcao que receba como parametro um vetor de estruturas do tipo Funcionario e
imprima o cargo e salario do Funcionario com maior salario e o cargo e salario do funcionario
com o menor salario*/

#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    char nome[50];
    float salario, alterado;
    int identificador;
    char cargo[30];

} Funcionario;

/* Funcao que recebe como parametro o endereco de uma estrutura do tipo Funcionario
e preenche seus campos com valores fornecidos pelo usuario via teclado.*/
Funcionario *cadastra_funcionario(int qnt_funcionarios)
{
    // Declaração de vetor do tipo funcionario
    Funcionario *vetor_funcionario = (Funcionario *)malloc(sizeof(Funcionario));
    if (vetor_funcionario == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    else
    {
        printf("Alocacao realizada com sucesso!\n");
    }
    int indice;
    for (indice = 0; indice < qnt_funcionarios; indice++)
    {
        printf("\n\tFuncionario %d\n ", indice + 1);
        printf("Digite o nome do Funcionario:\n ");
        scanf(" %[^\n]", vetor_funcionario[indice].nome);

        printf("Digite o salario do Funcionario:\n ");
        scanf("%f", &vetor_funcionario[indice].salario);

        printf("Digite o identificador do Funcionario:\n ");
        scanf("%d", &vetor_funcionario[indice].identificador);

        printf("Digite o cargo do Funcionario:\n ");
        scanf("%s", &vetor_funcionario[indice].cargo);
    }

    return vetor_funcionario;
}

/* Funcao que recebe como parametro o endereco de uma estrutura do tipo Funcionario
e imprime os valores dos seus campos.*/
void imprime(Funcionario *vetor_funcionario, int qnt_funcionarios)
{
    printf("\n\n\t\t DADOS DOS FUNCIONARIOS \n");
    int indice;
    for (indice = 0; indice < qnt_funcionarios; indice++)
    {
        printf("\nFuncionario %d\n ", indice + 1);

        printf("\nNome: %s \t Salario: %.2f \t Identificador: %d \t Cargo: %s\n", vetor_funcionario[indice].nome, vetor_funcionario[indice].salario, vetor_funcionario[indice].identificador, vetor_funcionario[indice].cargo);
    }
}

/* Funcao que realiza uma alteracao no salario de uma estrutura do tipo Funcionario.*/
void altera_salario(Funcionario *vetor_funcionario, int qnt_funcionarios)
{
    int indice;
    for (indice = 0; indice < qnt_funcionarios; indice++)
    {
        printf("\nFuncionario %d\n ", indice + 1);
        printf("Digite o salario alterado do Funcionario:\n ");
        scanf("%f", &vetor_funcionario[indice].alterado);
        vetor_funcionario[indice].salario = vetor_funcionario[indice].alterado;
    }
}

/* Funcao que recebe como parametro um vetor de estruturas do tipo Funcionario e
imprima o cargo e salario do Funcionario com maior salario e o cargo e salario do funcionario
com o menor salario.*/
void maiorEmenorSalario(Funcionario *vetor_funcionario, int qnt_funcionarios)
{
    int indice, maior = 0, menor = 0;
    for (indice = 0; indice < qnt_funcionarios; indice++)
    {
        if (vetor_funcionario[indice].salario > vetor_funcionario[maior].salario)
        {
            maior = indice;
        }
        if (vetor_funcionario[indice].salario < vetor_funcionario[menor].salario)
        {
            menor = indice;
        }
    }
    printf("\nCargo: %s  \t  Maior Salario: %.2f \nCargo: %s  \t  Menor Salario: %.2f", vetor_funcionario[maior].cargo, vetor_funcionario[maior].salario, vetor_funcionario[menor].cargo, vetor_funcionario[menor].salario);
}

/* Função main para testar todas as demais funções declaradas nos itens anteriores*/
int main(void)
{
    int qnt_funcionarios;
    printf("Digite a quantidade de funcionarios a ser cadastrada no sistema.\n");
    scanf("%d", &qnt_funcionarios);

    Funcionario *vetor_funcionario = cadastra_funcionario(qnt_funcionarios);

    imprime(vetor_funcionario, qnt_funcionarios);

    altera_salario(vetor_funcionario, qnt_funcionarios);

    maiorEmenorSalario(vetor_funcionario, qnt_funcionarios);

    free(vetor_funcionario);

    return 0;
}
