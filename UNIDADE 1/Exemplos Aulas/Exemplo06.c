// Programa que cadastra contas bancarias

#include <stdio.h>
#include <stdlib.h>
// Passo 1- Definir a struct que representa a conta
typedef struct conta
{
    char nome[50];
    int agencia;
    int num_conta;
    char nome_banco[30];

} Conta;

// Passo 1- Função que Cadastra contas

Conta *cadastraContas(int qnt_contas)
{
    /* Função que cadastra contas */

    // Declaração de vetor do tipo Conta
    Conta *vetor_contas = (Conta *)malloc(qnt_contas * sizeof(vetor_contas));
    if (vetor_contas == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    else
    {
        printf("Alocacao realizada com sucesso!\n");
    }

    // Preenche o vetor contas
    int indice;
    for (indice = 0; indice < qnt_contas; indice++)
    {
        printf("\n\tConta %d\n ", indice + 1);

        printf("Digite o nome do usuario da conta:\n ");
        scanf(" %[^\n]", vetor_contas[indice].nome);

        printf("Digite o nome do banco:\n ");
        scanf("%s", vetor_contas[indice].nome_banco);

        printf("Digite a agencia:\n ");
        scanf("%d", &vetor_contas[indice].agencia);

        printf("Digite o numero da conta:\n ");
        scanf("%d", &vetor_contas[indice].num_conta);
    }
    return vetor_contas;
}

// Passo 3 - Função que imprime os dados das contas cadastrados

void imprimeContas(Conta *vetor_contas, int qnt_contas)
{
    printf("\n\n\t DADOS DAS CONTAS \n");
    int indice;
    for (indice = 0; indice < qnt_contas; indice++)
    {
        printf("\n\tConta %d\n ", indice + 1);
        printf("Nome do Usuario: %s \n Nome do Banco: %s \n Agencia: %d \n Numero da Conta: %d\n ",
               vetor_contas[indice].nome, vetor_contas[indice].nome_banco, vetor_contas[indice].agencia, vetor_contas[indice].num_conta);
    }
}

int main(void)
{
    int qnt_contas;
    printf("Digite numero de contas a serem cadastrada no sistema.\n");
    scanf("%d", &qnt_contas);

    Conta *vetor = cadastraContas(qnt_contas);

    imprimeContas(vetor, qnt_contas);

    return 0;
} 