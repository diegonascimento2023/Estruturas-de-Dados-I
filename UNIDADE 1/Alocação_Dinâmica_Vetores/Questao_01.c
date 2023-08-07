/*Questão 1) Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um
novo produto. Um número N de pessoas de ambos os sexos foi entrevistado, e o questionário
consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opinião sobre o
produto (gostou/não gostou). Escreva um programa em C que:
a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados,
um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta
para a segunda pergunta.
b) determine a porcentagem de pessoas do sexo feminino que responderam que
gostaram do produto.
c) determine a porcentagem de pessoas do sexo masculino que responderam que não
gostaram do produto.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *sexo, *opiniao;
    int N, i, f_gostou = 0, m_naogostou = 0;
    float porcentagem_f, porcentagem_m;

    printf("Digite o numero de entrevistados.");
    scanf("%d", &N);

    sexo = (char *)(malloc(N * sizeof(char)));
    opiniao = (char *)(malloc(N * sizeof(char)));

    if (sexo == NULL || opiniao == NULL)
    {
        printf("\n Erro! Memoria insuficiente.");
        exit(1);
    }

    printf("\n");

    for (i = 0; i < N; i++)
    {
        printf("\t\tResposta %d\n", i + 1);
        printf("Digite o sexo do entrevistado. M para masculino e F para feminino.\n");
        scanf(" %c", &sexo[i]);
        printf("\nDigite a opiniao do entrevistado em relacao ao produto, gostou(g) ou nao gostou(n).\n");
        scanf(" %c", &opiniao[i]);
    }

    printf("\n");

    for (i = 0; i < N; i++)
    {
        if (sexo[i] == 'F' && opiniao[i] == 'g')
        {
            f_gostou = f_gostou + 1;
        }
        else if (sexo[i] == 'M' && opiniao[i] == 'n')
        {
            m_naogostou = m_naogostou + 1;
        }
    }
    porcentagem_f = ((float)f_gostou / N) * 100;
    porcentagem_m = ((float)m_naogostou / N) * 100;

    printf("\nPorcentagem de mulheres que gostaram do produto: %.2f%%\n", porcentagem_f);
    printf("\nPorcentagem de homens que  nao gostaram do produto: %.2f%%\n", porcentagem_m);

    free(sexo);
    free(opiniao);

    return 0;
}
