/*2. Escreva um programa que implementa uma struct Produto com os campos nome, preco e tipo. O tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto.*/

#include <stdio.h>
#include <stdlib.h>

//implementacao union Tipo
typedef union tipo
{
    int ALIMENTO, BEBIDA, ELETRONICO;
} Tipo;

//implementacao  struct Pessoa
typedef struct produto
{
    char nome[20];
    float preco;
    Tipo tipo_a;
} Produto;

//Função main para  ler e imprimir os dados
int main(void)
{
    // Declaração de vetor do tipo produto
    Produto *produto = (Produto *)malloc(sizeof(Produto));
    if (produto == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    else
    {
        printf("Alocacao realizada com sucesso!\n");
    }

    Tipo tipo_a;
    int T;

    printf("Digite o nome do produto:\n ");
    scanf(" %[^\n]", produto->nome);
    printf("Digite o preco do produto:\n ");
    scanf("%f", &produto->preco);

    printf("Digite o tipo do produto: \n 0-ALIMENTO \n 1-BEBIDA \n 2-ELETRONICO\n");
    scanf("%d", &produto->tipo_a.ALIMENTO);

    if (produto->tipo_a.ALIMENTO == 0)
    {
        printf("\n\t DADOS DO PRODUTO\n Nome: %s\n Preco: R$ %.2f\n Tipo: Alimento\n ", produto->nome, produto->preco);
    }
    else if (produto->tipo_a.ALIMENTO == 1)
    {
        printf("\n\t DADOS DO PRODUTO\n Nome: %s\n Preco: R$ %.2f\n Tipo: Bebida\n ", produto->nome, produto->preco);
    }
    else if (produto->tipo_a.ALIMENTO == 2)
    {
        printf("\n\t DADOS DO PRODUTO\n Nome: %s\n Preco: R$ %.2f\n Tipo: Eletronico\n ", produto->nome, produto->preco);
    }
    else
    {
        printf("Erro");
    }

    free(produto);
    return 0;
}