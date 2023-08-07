// Progama que manipula dados de uma pessoa e armazena em uma struct
#include <stdio.h>

typedef struct pessoa
{
    char nome[20];
    int idade;
    int RG;
    float altura;

} Pessoa;

// typedef struct aluno Aluno
//  typedef: Permite renomear qualquer variavel.

int main(void)
{
    Pessoa var_pessoa[2];

    int indice;
    for (indice=0; indice<2; indice++)
    {
        printf("\n\t\t Dados pessoa: %d\n", indice + 1 );
        printf("Digite o nome:\n ");
        scanf(" %[^\n]", var_pessoa[indice].nome);

        printf("Digite a idade:\n ");
        scanf("%d", &var_pessoa[indice].idade);

        printf("Digite a RG:\n ");
        scanf("%d", &var_pessoa[indice].RG);

        printf("Digite a altura:\n ");
        scanf("%f", &var_pessoa[indice].altura);

        printf(" Os dados informados:\n Nome: %s \t Idade: %d \t RG: %d \t Altura: %.2f\n", var_pessoa[indice].nome, var_pessoa[indice].idade, var_pessoa[indice].RG, var_pessoa[indice].altura);
        
        printf("\n");
    }
    return 0;
}
