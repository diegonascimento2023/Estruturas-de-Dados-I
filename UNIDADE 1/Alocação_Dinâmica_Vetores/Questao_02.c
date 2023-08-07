/*Questão 2) Escreva um programa para corrigir provas de múltipla escolha. Cada prova tem N
questões e cada questão vale 10/N pontos. Os primeiros dados a serem lidos são o número de
questões e o gabarito da prova. Em seguida, serão lidas as respectivas respostas de um total de
10 alunos matriculados. Calcule e mostre:
a) a nota obtida para cada aluno;
b) a porcentagem de aprovação, sabendo-se que a nota mínima para ser aprovado é 6.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    char *gabarito;
    int N, i, j, alunos_aprovados = 0;
    float *notas, nota = 0, nota_minima = 6.0;

    printf("Digite o numero de questoes: \n");
    scanf("%d", &N);

    gabarito = (char *)malloc(N * sizeof(char));
    if (gabarito == NULL)
    {
        printf("\nErro! Memoria insuficiente.");
        exit(1);
    }

    printf("\n");
    for (i = 0; i < N; i++)
    {
        printf("Questao %d:\n", i + 1);
        printf("Digite a resposta correta (A, B, C, D ou E): ");
        scanf(" %c", &gabarito[i]);

        // Validação da resposta do professor
        if (gabarito[i] < 'A' || gabarito[i] > 'E')
        {
            printf("Resposta invalida! Digite novamente.\n");
            i--;
        }
    }

    notas = (float *)malloc(10 * sizeof(float));
    if (notas == NULL)
    {
        printf("\nErro! Memoria insuficiente.");
        free(gabarito);
        exit(1);
    }

    printf("\n");
    for (j = 0; j < 10; j++)
    {
        printf("\n\t\tAluno %d:\n", j + 1);

        char *resposta_aluno = (char *)malloc(N * sizeof(char));
        if (resposta_aluno == NULL)
        {
            printf("\nErro! Memoria insuficiente.");
            free(gabarito);
            free(notas);
            exit(1);
        }

        for (i = 0; i < N; i++)
        {
            printf("Digite a resposta da questao %d: \n", i + 1);
            scanf(" %c", &resposta_aluno[i]);

            // Validação da resposta do aluno
            if (resposta_aluno[i] < 'A' || resposta_aluno[i] > 'E')
            {
                printf("Resposta invalida! Digite novamente.\n");
                i--;
            }
        }

        // Cálculo da nota do aluno
        for (i = 0; i < N; i++)
        {
            if (resposta_aluno[i] == gabarito[i])
            {
                nota += 10.0 / N;
            }
        }

        notas[j] = nota;
        free(resposta_aluno);

        printf("Nota: %.2f\n", nota);

        // Verifica se o aluno foi aprovado
        if (nota >= nota_minima)
        {
            alunos_aprovados++;
        }
    }

    // Calcula a porcentagem de aprovação
    float porcentagem_aprovacao = (float)alunos_aprovados / 10 * 100;

    printf("\nPorcentagem de aprovacao: %.2f%%\n", porcentagem_aprovacao);

    free(gabarito);
    free(notas);

    return 0;
}
