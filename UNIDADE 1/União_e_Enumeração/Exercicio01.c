/*1.  Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e genero. O genero deve ser armazenado como um enum com os valores MASCULINO e FEMININO. O programa deve ler os dados de uma pessoa e imprimir os dados da pessoa.*/

#include <stdio.h>
#include <stdlib.h>

//implementacao  enum Genero
typedef enum genero
{
    MASCULINO,
    FEMININO

} Genero;

//implementacao  struct Pessoa
typedef struct pessoa
{
    int idade;
    char nome[20];
    Genero g;
} Pessoa;

//Função main para  ler e imprimir os dados*/
int main(void)
{
    // Declaração de vetor do tipo pessoa
    Pessoa *pessoa = (Pessoa *)malloc(sizeof(Pessoa));
    if (pessoa == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    else
    {
        printf("Alocacao realizada com sucesso!\n");
    }

    printf("Digite o nome:\n ");
    scanf(" %[^\n]", pessoa->nome);
    printf("Digite a idade:\n ");
    scanf("%d", &pessoa->idade);

    printf(" Digite o genero: 0 para Masculino e 1 para Feminino.\n");
    scanf("%d", &pessoa->g);

    printf("\n\t DADOS PESSOA\n Nome: %s\n Idade: %d\n Genero: %s", pessoa->nome, pessoa->idade, pessoa->g == MASCULINO ? "Masculino" : "Feminino");
    
    free(pessoa);
    return 0;
}
