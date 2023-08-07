/*3. Crie um programa em C que leia um numero inteiro positivo n do usuario e aloque dinamicamente
memoria para armazenar uma matriz quadrada de ordem n. Preencha essa matriz com numeros
aleatorios entre 1 e 100, e em seguida, exiba a matriz resultante.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

    int ordem_m;

    do
    {
        printf("Digite o numero correspondente a ordem da matriz quadrada.\n");
        scanf("%d", &ordem_m);

        if (ordem_m <= 0)
        {
            printf("Numero invalido. Por favor, digite um numero inteiro positivo.\n");
        }
    } while (ordem_m < 0);

    // Alocação de memória para a matriz
    int i, j;
    int **matriz = (int **)malloc(ordem_m * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }

    for (i = 0; i < ordem_m; i++)
    {
        matriz[i] = (int *)malloc(ordem_m * sizeof(int));
        if (matriz == NULL)
        {
            printf("Erro de alocacao de memoria.\n");
            exit(1);
        }
    }

    // Preenchimento da matriz com numeros aleatorios entre 1 e 100
    srand(time(NULL));
    for (i = 0; i < ordem_m; i++)
    {
        for (j = 0; j < ordem_m; j++)
        {
            matriz[i][j] = 1 + rand() % 100;
        }
    }
    // Exibindo a matriz

    printf("\t\tMatriz de ordem n com numeros aleatorios entre 1 e 100.\n");

    for (i = 0; i < ordem_m; i++)
    {
        for (j = 0; j < ordem_m; j++)
        {
            printf("%02d ", matriz[i][j]);
        }
        printf("\n");
    }
    // Liberação da memória alocada
    for (i = 0; i < ordem_m; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
