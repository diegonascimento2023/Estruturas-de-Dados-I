#include <stdio.h>
#include <stdlib.h>

//Função que recebe dois vetores como entrada e retorna um novo vetor que contem a soma dos elementos correspondentes dos vetores de entrada.
int *soma(int *v1, int *v2, int tam)
{
    int *v_soma = (int *)malloc(tam * sizeof(int));
    if (v_soma == NULL)
    {
        printf(" Memoria insuficiente!");
        exit(1);
    }
    int i;
    for (i = 0; i < tam; i++)
    {
        v_soma[i] = v1[i] + v2[i];
    }
    return v_soma;
}

//Funçao main apenas para mostrar a funçao soma realmente funciona.
int main(void)
{
    int v1[] = {1, 2, 3};
    int v2[] = {3, 2, 1};
    int i, tam = 3;

    soma(v1, v2, tam);
    int *vetor = (int *)malloc(tam * sizeof(int));
    if (vetor == NULL)
    {
        printf(" Memoria insuficiente!");
        exit(1);
    }
    vetor = soma(v1, v2, tam);
    for (i = 0; i < tam; i++)
    {
        printf("%d", vetor[i]);
    }
    free(vetor);
    return 0;
}
