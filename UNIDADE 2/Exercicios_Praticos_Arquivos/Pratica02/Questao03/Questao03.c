/* programa em C para ler o nome e as notas de um numero N de alunos e armazena-los
em um arquivo*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_FRUTAS 10
typedef struct fruta
{
    char nome[30];
    float preco;

} Fruta;

int main(void)
{
    FILE *frutas_saida;

    // Aloca memoria dinamicamente
    Fruta *fruta = (Fruta *)malloc(MAX_FRUTAS * sizeof(Fruta));
    if (fruta == NULL)
    {
        printf("\n Erro! Memoria insuficiente.");
        exit(1);
    }

    // Abrir/criar o arquivo de saida para escrita (w)
    frutas_saida = fopen("frutas.txt", "w");
    if (frutas_saida == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    // Escreve no arquivo de saida os dados do funcionario
    fprintf(frutas_saida, "NOME,PRECO\n");

    // Armazena os dados de quantas frutas o usuario decidir
    // Quando o usuario desejar sair, digita 2
    int resp;
    int i=0;
    do
    {
        printf("\tFruta %d\n", (i + 1));
        printf("Digite o nome da fruta.\n");
        scanf(" %[^\n]", fruta->nome);

        printf("Digite o preco de %s.\n", fruta->nome);
        scanf("%f", &fruta->preco);

        fprintf(frutas_saida, "%s,%.2f\n", fruta->nome, fruta->preco);
         i++;

        printf("Digite 1 para continuar ou 2 para sair\n");
        scanf("%d", &resp);
        printf("Cadastramento Finalizado! Obrigado por utilizar o programa.\n");

    } while (resp == 1);
     
     fruta = realloc(fruta, i * sizeof(Fruta));


    // Fecha os arquivos abertos
    fclose(frutas_saida);

    // Libera memoria
    free(fruta);

    return 0;
}