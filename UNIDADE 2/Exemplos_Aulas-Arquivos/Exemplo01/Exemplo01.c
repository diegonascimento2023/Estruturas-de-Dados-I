#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float numero = 3.14;
    char nome_arquivo[20];
    int c;
    printf("Informe o nome do arquivo: \n");
    scanf(" %[^\n]", nome_arquivo); // exemplo:arquivo.txt

    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    else
    {
        printf("Arquivo criado com sucesso.");
        /* code */
    }
    
    // fputs("Diego Nascimento de Oliveira", arquivo); // Lê uma linha do arquivo fp e armazena na string str com no máximo 100 caracteres
    
    fprintf(arquivo, "Diego Nascimento: %.2f \n", numero); // Escreve a string "Diego Nascimento: 3.14" no arquivo apontado por fp
    
    fclose(arquivo);                                       // fecha arquivo
    
    return 0;
}
