#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int c;
    char entrada[121]; // armazena o nome do arquivo de entrada
    char saida[121];   // armazena o nome do arquivo de saida
    FILE *e;
    FILE *s;

    printf("Digite o nome do arquivo de entrada: ");
    scanf(" %[^\n]s", entrada);
    printf("Digite o nome do arquivo de saida: ");
    scanf(" %[^\n]s", saida);

    e = fopen(saida, "wt");
    if (e == NULL)
    {
        printf("Nao foi possivel abrir o arquivo de entrada.");
        return 1;
    }
    s = fopen(saida, "wt");
    if (s == NULL)
    {
        printf("Nao foi possivel abrir o arquivo de saida. ");
        fclose(e);
        return 1;
    }

    while ((c = fgetc(e)) != EOF)
    {
        fputc(toupper(c), s);
    // fecha arquivo
    }
     // fecha arquivos
    fclose(e);
    fclose(s);

   
    return 0;
}