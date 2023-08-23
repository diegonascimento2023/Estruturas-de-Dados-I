#include <stdio.h>
#include "aluno.c"
#include "disciplina.h"

int main() {
    Disciplina* disciplina1 = criaDisciplina("Matematica", 1);
    Disciplina* disciplina2 = criaDisciplina("Historia", 2);

    Aluno* aluno1 = cria_aluno("Joao", 1001);
    Aluno* aluno2 = cria_aluno("Maria", 1002);

    matricula_disciplina(aluno1, disciplina1);
    matricula_disciplina(aluno1, disciplina2);
    matricula_disciplina(aluno2, disciplina1);

    printf("Informacoes do Aluno 1:\n");
    printf("Nome: %s\nMatricula: %d\n", aluno1->nome, aluno1->matricula);
    printf("Disciplinas matriculadas:\n");
    for (int i = 0; i < aluno1->num_disciplinas; i++) {
        printf("- %s\n", aluno1->disciplinas[i]->nome);
    }

    printf("\nInformacoes do Aluno 2:\n");
    printf("Nome: %s\nMatricula: %d\n", aluno2->nome, aluno2->matricula);
    printf("Disciplinas matriculadas:\n");
    for (int i = 0; i < aluno2->num_disciplinas; i++) {
        printf("- %s\n", aluno2->disciplinas[i]->nome);
    }

    exclui_aluno(aluno1);
    exclui_aluno(aluno2);
    exclui_disciplina(disciplina1);
    exclui_disciplina(disciplina2);

    return 0;
}
