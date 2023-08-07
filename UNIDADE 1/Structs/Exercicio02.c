/*1. Crie um tipo estruturado para armazenar dados de uma pessoa. Uma estrutura deste tipo possui
os seguintes campos:nome da pessoa, numero do documento e idade.
a) Escreva uma funcao que receba como parametro o endereco de uma estrutura do tipo Pessoa
e preencha seus campos com valores fornecidos pelo usuario via teclado.
b) Escreva uma funcao que receba como parametro o endereco de uma estrutura do tipo Pessoa
e imprima os valores dos seus campos.
c) Implemente uma funcao para realizar uma atualização na idade de uma estrutura do tipo Pessoa.
d) Escreva uma funcao que receba como parametro um vetor de estruturas do tipo Pessoa e imprima
o nome da Pessoa mais velha e mais nova*/

#include <stdio.h>
#include <stdlib.h>

// Declarando estrutura do tipo pessoa
typedef struct pessoa
{
    char nome[50];
    int num_documento, idade, atualizada;

} Pessoa;

/* Funcao que recebe como parametro o endereco de uma estrutura do tipo Pessoa
e preenche seus campos com valores fornecidos pelo usuario via teclado.*/
Pessoa *cadastra_pessoa(int qnt_pessoas)
{
    // Declaração de vetor do tipo pessoa
    Pessoa *vetor_pessoa = (Pessoa *)malloc(sizeof(Pessoa));
    if (vetor_pessoa == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    else
    {
        printf("Alocacao realizada com sucesso!\n");
    }
    int indice;
    for (indice = 0; indice < qnt_pessoas; indice++)
    {
        printf("\n\tPessoa %d\n ", indice + 1);
        printf("Digite o nome da Pessoa:\n ");
        scanf(" %[^\n]", vetor_pessoa[indice].nome);

        printf("Digite o numero do documento da Pessoa:\n ");
        scanf("%d", &vetor_pessoa[indice].num_documento);

        printf("Digite a idade da Pessoa:\n ");
        scanf("%d", &vetor_pessoa[indice].idade);

        
    }

    return vetor_pessoa;
}

/* Funcao que recebe como parametro o endereco de uma estrutura do tipo Pessoa
e imprime os valores dos seus campos.*/
void imprime(Pessoa *vetor_pessoa, int qnt_pessoas)
{
    printf("\n\n\t\t DADOS DAS PESSOAS \n");
    int indice;
    for (indice = 0; indice < qnt_pessoas; indice++)
    {
        printf("\nPessoa %d\n ", indice + 1);

        printf("\nNome: %s \t Numero do Documento: %d \t Idade: %d\n", vetor_pessoa[indice].nome, vetor_pessoa[indice].num_documento, vetor_pessoa[indice].idade);
    }
}

/* Funcao que realiza uma atualização na idade de uma estrutura do tipo Pessoa.*/
void altera_idade(Pessoa *vetor_pessoa, int qnt_pessoas)
{
    int indice;
    for (indice = 0; indice < qnt_pessoas; indice++)
    {
        printf("\nPessoa %d\n ", indice + 1);
        printf("Digite a atualizacao da idade da Pessoa:\n ");
        scanf("%d", &vetor_pessoa[indice].atualizada);
        vetor_pessoa[indice].idade = vetor_pessoa[indice].atualizada;
    }
}

/* Funcao que recebe como parametro um vetor de estruturas do tipo Pessoa e
imprima a idade da Pessoa com maior idade e da Pessoa
com o menor idade.*/
void maiorEmenoridade(Pessoa *vetor_pessoa, int qnt_pessoas)
{
    int indice, maior = 0, menor = 0;
    for (indice = 0; indice < qnt_pessoas; indice++)
    {
        if (vetor_pessoa[indice].idade > vetor_pessoa[maior].idade)
        {
            maior = indice;
        }
        if (vetor_pessoa[indice].idade < vetor_pessoa[menor].idade)
        {
            menor = indice;
        }
    }
    printf("\nNome pessoa mais velha: %s  \nNome pessoa mais nova: %s\n", vetor_pessoa[maior].nome, vetor_pessoa[menor].nome);
}

/* Função main para testar todas as demais funções declaradas nos itens anteriores*/
int main(void)
{
    int qnt_pessoas;
    printf("Digite a quantidade de Pessoas a ser cadastrada no sistema.\n");
    scanf("%d", &qnt_pessoas);

    Pessoa *vetor_pessoa = cadastra_pessoa(qnt_pessoas);
    
    altera_idade(vetor_pessoa, qnt_pessoas);

    imprime(vetor_pessoa, qnt_pessoas);

   
    maiorEmenoridade(vetor_pessoa, qnt_pessoas);

    free(vetor_pessoa);

    return 0;
}
