/*4. Voce foi contratado para desenvolver um programa em C que permita armazenar nomes completos
e idades de varias pessoas. O programa deve solicitar ao usuario o numero de pessoas e, em seguida,
permitir que ele digite o nome completo e a idade de cada pessoa.
Seu programa deve alocar memoria dinamicamente para armazenar os nomes em uma matriz de
strings, e as idades devem ser armazenadas em um vetor. Apos a entrada de todos os nomes e idades,
o programa deve exibir os nomes armazenados.
Aqui estao as especifica¸c˜oes do programa:
– O programa deve come¸car solicitando ao usuario o n´umero de pessoas que deseja armazenar.
– Em seguida, o programa deve pedir ao usuario que digite o nome completo de cada pessoa.
– Os nomes devem ser armazenados em uma matriz alocada dinamicamente.
– Ap´os o nome, o programa deve solicitar a idade da pessoa.
– As idades devem ser armazenadas em um vetor alocado dinamicamente.
– Ap´os a entrada de todos os nomes e idades, o programa deve exibir os nomes armazenados.
– Certifique-se de tratar adequadamente a alocacao dinamica de memoria e liberar a memoria
alocada corretamente apos o uso.
Observacao: O programa deve ser capaz de armazenar ate 100 nomes completos.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numero_p;
    int tam_max = 100;
    int i;

    do
    {
        printf("Digite o numero de pessoas: ");
        scanf("%d", &numero_p);

        if (numero_p <= 0 || numero_p > 100)
        {
            printf("Numero invalido. Digite um numero inteiro positivo menor ou igual a 100.\n");
        }
    } while (numero_p <= 0 || numero_p > 100);

    // Alocação de memória para a matriz
    char **matriz = (char **)malloc(numero_p * sizeof(char *));
    if (matriz == NULL)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }

    // Alocação de memória para o vetor
    int *vetor = (int *)malloc(numero_p * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }

    // Preenchendo a matriz de strings
    for (i = 0; i < numero_p; i++)
    {
        matriz[i] = (char *)malloc((tam_max + 1) * sizeof(char));
        if (matriz[i] == NULL)
        {
            printf("Erro de alocacao de memoria.\n");
            exit(1);
        }

        // Preenchimento da matriz com strings
        printf("Digite o nome completo da pessoa %d: ", i + 1);
        scanf(" %[^\n]s", matriz[i]);

        // Preenchimento do vetor com as idades
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Exibindo a matriz de nomes
    printf("\n\tMatriz de nomes:\n");
    for (i = 0; i < numero_p; i++)
    {
        printf("Nome pessoa %d: %s\n", i + 1, matriz[i]);
    }

    // Liberação da memória alocada
    for (i = 0; i < numero_p; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    free(vetor);

    return 0;
}
