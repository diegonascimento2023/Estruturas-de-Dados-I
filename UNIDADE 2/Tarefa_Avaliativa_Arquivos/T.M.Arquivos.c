#include <stdio.h>
#include <stdlib.h>

#define MAX_FUNCIONAL 10
#define MAX_NOME 20

typedef struct funcionario
{
    char funcional[MAX_FUNCIONAL];
    char nome[MAX_NOME];
    char departamento;
    float salario;
} Funcionario;

void copia_dados(FILE *fl, int n, Funcionario **pessoal)
{
    *pessoal = (Funcionario *)malloc(n * sizeof(Funcionario));
    if (*pessoal == NULL)
    {
        printf("\n Erro! Memoria insuficiente.");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fl, "%s\t%s\t%c\t%f", (*pessoal)[i].funcional, (*pessoal)[i].nome, &(*pessoal)[i].departamento, &(*pessoal)[i].salario);
        (*pessoal)[i].departamento = (*pessoal)[i].departamento; // Apenas para garantir que o campo departamento esteja correto
    }

    fclose(fl);
}

void imprime_folha_pagamento(int n, Funcionario **pessoal, char depto)
{
    float valorGasto = 0;
    printf("FOLHA DE PAGAMENTO DEPTO %c\n", depto);
    printf("FUNCIONAL\tNOME\t\tDEPTO\t\tSALARIO\n");
    for (int i = 0; i < n; i++)
    {
        if ((*pessoal)[i].departamento == depto)
        { 
            printf("%s\t\t%s\t\t%c\t\t%.2f\n", (*pessoal)[i].funcional, (*pessoal)[i].nome, (*pessoal)[i].departamento, (*pessoal)[i].salario);
            valorGasto += (*pessoal)[i].salario;
            
        }
    }
    printf("VALOR TOTAL: R$ %.2f\n\n", valorGasto);
}

int main(void)
{
    int num_func;
    Funcionario *pessoal;
    FILE *fl;
    char depto;

    fl = fopen("folhaPagamento.txt", "r");
    if (fl == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fscanf(fl, "%d", &num_func);

    copia_dados(fl, num_func, &pessoal);
    imprime_folha_pagamento(num_func, &pessoal, 'A');
    imprime_folha_pagamento(num_func, &pessoal, 'B');
    imprime_folha_pagamento(num_func, &pessoal, 'C');

    free(pessoal);

    return 0;
}
