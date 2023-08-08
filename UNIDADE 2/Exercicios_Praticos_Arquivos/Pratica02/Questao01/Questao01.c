/*Programa em C que solicita ao usuario informacoes de funcionarios via teclado. As informacoes digitadas pelo o usuario sao: id, nome e salario do funcionario. Armazene as informacoes
digitadas pelo usuario em um arquivo texto*/

#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    int id;
    char nome[30];
    float salario;

} Funcionario;

int main(void)
{
    FILE *arquivo_saida;
    int num_funcionarios;

    //Solicita ao usuario o numero de funcionarios
    printf("Digite o numero de funcionarios.\n");
    scanf("%d", &num_funcionarios);
    
    //Aloca memoria dinamicamente
    Funcionario *funcionario = (Funcionario *)malloc(num_funcionarios * sizeof(Funcionario));
    if (funcionario == NULL)
    {
        printf("\n Erro! Memoria insuficiente.");
        exit(1);
    }

    // Abrir/criar o arquivo de saida para escrita (w)
    arquivo_saida = fopen("saida_q3.txt", "w");
    if (arquivo_saida == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    
    //Armazena os dados na struct do tipo Funcionario
    int i;
    for (i = 0; i < num_funcionarios; i++)
    {
        printf("Funcionario %d\n", (i + 1));
        printf("Digite o id do funcionario.\n");
        scanf("%d", &funcionario[i].id);

        printf("Digite o nome do funcionario.\n");
        scanf(" %[^\n]", funcionario[i].nome);

        printf("Digite o salario do funcionario.\n");
        scanf("%f", &funcionario[i].salario);
    }

    // Escreve no arquivo de saida os dados do funcionario
    fprintf(arquivo_saida, "ID\tNOME\tSALARIO\n");
    for (i = 0; i < num_funcionarios; i++)
    {
        fprintf(arquivo_saida, "%d\t%s\tR$ %.2f\n", funcionario[i].id, funcionario[i].nome, funcionario[i].salario);
    }

    // Fecha os arquivos abertos
    fclose(arquivo_saida);

    //Libera memoria alocada
    free(funcionario);

    return 0;
}