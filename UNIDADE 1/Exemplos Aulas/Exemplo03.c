// Progama que manipula dados de uma conta bancaria e armazena em uma struct
#include <stdio.h>

typedef struct conta
{
    int agencia;
    int num_conta;
    int senha;
    float saldo;
    char nome[20];

} ContaBancaria;

// typedef struct aluno Aluno
//  typedef: Permite renomear qualquer variavel.

int main(void)
{
    ContaBancaria var_conta[2];

    int indice;
    for (indice = 0; indice < 2; indice++)
    {
        printf("\n\t\t Dados Conta Bancaria %d\n", indice + 1);
        printf("Digite o nome:\n ");
        scanf(" %[^\n]", var_conta[indice].nome);

        printf("Digite a agencia:\n ");
        scanf("%d", &var_conta[indice].agencia);

        printf("Digite o numero da conta:\n ");
        scanf("%d", &var_conta[indice].num_conta);

        printf("Digite a senha:\n ");
        scanf("%d", &var_conta[indice].senha);

        printf("Digite a saldo:\n ");
        scanf("%f", &var_conta[indice].saldo);

        printf(" Os dados informados:\n Nome: %s \t Agencia: %d \t Numero da Conta: %d \t Senha: %d \t Saldo: %.2f\n", var_conta[indice].nome, var_conta[indice].agencia, var_conta[indice].num_conta, var_conta[indice].senha, var_conta[indice].saldo);

        printf("\n");
    }
    return 0;
}
