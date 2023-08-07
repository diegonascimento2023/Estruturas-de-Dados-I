/*1. Escreva um programa em C que solicite ao usuario o tamanho de um vetor e, em seguida, aloque
dinamicamente memoria para armazenar esse vetor. Depois disso, peca ao usuario que insira os
elementos do vetor e, por fim, imprima os elementos na ordem inversa*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Alocação de memória para o vetor
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    else
    {
        printf("Alocacao realizada com sucesso!\n");
    }

    // Solicitando que o usuario insira os elementos do vetor
    printf("Digite os valores do vetor:\n");
    for (i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    // Imprimindo os elementos na ordem inversa do que foi digitado pelo usuario
    printf("Vetor invertido:\n");
    for (i = tamanho - 1; i >= 0; i--)
    {
        printf("%d\n", vetor[i]);
    }

    free(vetor);
    return 0;
}
