/*2. Implemente um programa em C que solicite ao usu´ario o n´umero de linhas e colunas de uma matriz e,
em seguida, aloque dinamicamente mem´oria para armazenar essa matriz. Pe¸ca ao usu´ario que insira
os elementos da matriz e, por fim, imprima a matriz na forma original e transposta.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int linhas, colunas;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    // Alocação de memória para a matriz original
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    int i, j;
    for (i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    // Preenchimento da matriz original
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Impressão da matriz original
    printf("\nMatriz original:\n");
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Alocação de memória para a matriz transposta
    int **matrizT = (int **)malloc(colunas * sizeof(int *));
    if (matrizT == NULL)
    {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    for (j = 0; j < colunas; j++)
    {
        matrizT[j] = (int *)malloc(linhas * sizeof(int));
    }

    // Cálculo e impressão da matriz transposta
    printf("\nMatriz transposta:\n");
    for (j = 0; j < colunas; j++)
    {
        for (i = 0; i < linhas; i++)
        {
            matrizT[j][i] = matriz[i][j];
            printf("%d ", matrizT[j][i]);
        }
        printf("\n");
    }

    // Liberação da memória alocada
    for (i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    for (j = 0; j < colunas; j++)
    {
        free(matrizT[j]);
    }
    free(matrizT);

    return 0;
}
