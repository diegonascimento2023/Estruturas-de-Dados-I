/* programa em C para ler o nome e as notas de um numero N de alunos e armazena-los
em um arquivo*/

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    char nome[30];
     float nota1, nota2, nota3;

} Aluno;

int main(void)
{
    FILE *arquivo_saida;
    int N;
   

    //Solicita ao usuario o numero de funcionarios
    printf("Digite o numero de alunos.\n");
    scanf("%d", &N);
    
    //Aloca memoria dinamicamente
    Aluno *aluno = (Aluno *)malloc(N * sizeof(Aluno));
    if (aluno == NULL)
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
    
    //Armazena os dados por meio de um vetor
    int i;
    for (i = 0; i < N; i++)
    {
        printf("\tAluno %d\n", (i + 1));
        printf("Digite o nome do aluno.\n");
        scanf(" %[^\n]", aluno[i].nome);

        printf("Digite a primeira nota de %s.\n", aluno[i].nome);
        scanf("%f", &aluno[i].nota1);

        printf("Digite a segunda nota de %s.\n", aluno[i].nome);
        scanf("%f", &aluno[i].nota2);

        printf("Digite a terceira nota de %s.\n", aluno[i].nome);
        scanf("%f", &aluno[i].nota3);
    }

    // Escreve no arquivo de saida os dados do funcionario
    fprintf(arquivo_saida, "NOME\t NOTA 1\t NOTA 2\t NOTA 3\n");
    for (i = 0; i < N; i++)
    {
        fprintf(arquivo_saida, "%s\t %.2f\t %.2f \t %.2f\n", aluno[i].nome, aluno[i].nota1, aluno[i].nota2,aluno[i].nota3);
    }

    // Fecha os arquivos abertos
    fclose(arquivo_saida);
    
    //Libera memoria
    free(aluno);

    return 0;
}