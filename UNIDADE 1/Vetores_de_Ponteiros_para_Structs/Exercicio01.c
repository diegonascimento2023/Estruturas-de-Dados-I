#include <stdio.h>
#include <stdlib.h>
#define MAX_VAGAS 60
#define MAX_TURMAS 1

struct aluno
{
    int mat;
    char nome[81];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;

struct turma
{
    char id;   /* caractere que identifica a turma, por exemplo, A ou B */
    int vagas; /* números de vagas disponíveis para fechar a turma */
    Aluno *alunos[MAX_VAGAS];
};
typedef struct turma Turma;
Turma *turmas[MAX_TURMAS];

/*a) Implemente uma função que cria uma turma, fornecendo-lhe um identificador.
Essa função deve ser responsável por indicar que a turma não tem alunos
matriculados, atribuindo a constante NULL a cada um dos elementos do vetor de
ponteiros.
Protótipo: Turma* cria_turma(char id)*/
Turma *cria_turma(char id, int vagas)
{
    // Declaração de vetor do tipo turma
    Turma *nova_turma = (Turma *)malloc(sizeof(Turma));
    if (nova_turma == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    nova_turma->id = id;
    nova_turma->vagas = vagas;

    // Inicializa o vetor de ponteiros para alunos com NULL
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        nova_turma->vagas = NULL;
    }
    printf("\nA turma nao possui alunos matriculados.\n");

    return nova_turma;
}

int main(void)
{  
    char  id;
    int vagas;
    cria_turma( id, vagas);
    return 0;
}
