#include <stdio.h>
#include <stdlib.h>

 typedef union documentos
{
    int CPF, RG, CNH;
}Docs;



int main(void)
{
    Docs documento;

    printf("Digite o cpf:\n ");
    scanf("%d", &documento.CPF);
    printf("Digite o rg:\n ");
    scanf("%d", &documento.RG);
    printf("Digite a cnh:\n ");
    scanf("%d", &documento.CNH);

    printf("\n Documentos: CPF %d RG %d CNH %d ", documento.CPF, documento.RG, documento.CNH );

    return 0;
}