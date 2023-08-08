/*Programa em C que le de um arquivo as notas dos alunos de uma turma e escreva em outro
 arquivo o nome e a média de cada aluno, bem como a sua situação (aprovado (média >= 7.0)
 ou reprovado). Tanto no arquivo de entrada quanto no de saída, os dados em cada linha estão
 separados por um caractere de tabulação ‘\t’. Para a execução do programa com o arquivo de entrada “entrada_q3.txt”, foi criado o arquivo de saída “saída_q3.txt”*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    FILE *arquivo_entrada, *arquivo_saida;
    char nome[100], linha[100];
    float nota1, nota2, nota3, media = 0;

    // Abrir o arquivo de entrada apenas para leitura (r)
    arquivo_entrada = fopen("entrada_q3.txt", "r");
    if (arquivo_entrada == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Abrir/criar o arquivo de saida para escrita (w)
    arquivo_saida = fopen("saida_q3.txt", "w");
    if (arquivo_saida == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    // Ler os dados do arquivo de entrada
    while (fgets(linha, 100, arquivo_entrada) != NULL)
    {
        sscanf(linha, "%20[^\t]%f\t%f\t%f", nome, &nota1, &nota2, &nota3);
        media = (nota1 + nota2 + nota3) / 3;
        // Escreve no arquivo de saida os dados de nome, media e aprovado/reprovado
        fprintf(arquivo_saida, "%s\t%.1f\t %s\n", nome, media, (media >= 7.0) ? "Aprovado" : "Reprovado");
    }
    // Fecha os arquivos abertos
    fclose(arquivo_entrada);
    fclose(arquivo_saida);
    return 0;
}