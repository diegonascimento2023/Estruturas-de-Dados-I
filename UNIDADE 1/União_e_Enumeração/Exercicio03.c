/*Escreva um programa que implementa uma struct Data com os campos dia, mes e ano. O mes deve ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARCO, ABRIL, MAIO,JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa deve ler a data e imprimir a data no formato dd/mm/aaaa.*/

#include <stdio.h>
#include <stdlib.h>

//implementacao enum Mes
typedef enum mes
{
    zero,
    JANEIRO,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO

} Mes;

//implementacao struct Data
typedef struct data
{
    int dia, ano;
    Mes m;

} Data;

//Função main para  ler e imprimir os dados
int main(void)
{
    // Declaração de vetor do tipo data
    Data *data = (Data *)malloc(sizeof(Data));
    if (data == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    else
    {
        printf("Alocacao realizada com sucesso!\n");
    }

    printf("Digite o dia:(dd)\n ");
    scanf("%d", &data->dia);
    printf("Digite o mes:\n 1-JANEIRO\n 2-FEVEREIRO\n 3-MARCO\n 4-ABRIL\n 5-MAIO\n 6-JUNHO\n 7-JULHO\n 8-AGOSTO\n 9-SETEMBRO\n 10-OUTUBRO\n 11-NOVEMBRO\n 12-DEZEMBRO\n");
    scanf("%d", &data->m);
    printf("Digite o ano:(aaaa)\n ");
    scanf("%d", &data->ano);

    printf("\nDATA\n%d/%d/%d", data->dia, data->m, data->ano);
    free(data);
    return 0;
}
