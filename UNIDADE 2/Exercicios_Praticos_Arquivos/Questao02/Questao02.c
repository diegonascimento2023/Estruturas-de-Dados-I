 /*Programa em C que preencha um vetor de 10 inteiros com informações
vindas de um arquivo e escreve em outro arquivo o menor elemento, o maior elemento, bem
como a média dos elementos do vetor.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, soma = 0, maior = 0, menor, n = 10;

    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL)
    {
        printf("Memoria insuficiente!");
        exit(1);
    }

    FILE *arquivo_entrada, *arquivo_saida;

    // Abrir o arquivo de entrada apenas para leitura (r)
    arquivo_entrada = fopen("entrada_q2.txt", "r");
    if (arquivo_entrada == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Abrir/criar o arquivo de saida para escrita (w)
    arquivo_saida = fopen("saida_q2.txt", "w");
    if (arquivo_saida == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    // Ler os dados do arquivo de entrada
    for (i = 0; i < n; i++)
    {
        fscanf(arquivo_entrada, " %d", &vetor[i]);

        // Indica maior valor
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }

        soma = soma + vetor[i];
    }

    // Indica menor valor
    for (i = 0; i < n; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }

    // Escreve no arquivo de saida o menor, maior e amedia dos elementos
    fprintf(arquivo_saida, "menor elemento: %d\nmaior elemento: %d\nmedia dos elementos: %.6f\n", menor, maior, (float)soma / n);

    // Fecha os arquivos abertos
    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    // Libera a memoria alocada
    free(vetor);

    return 0;
}