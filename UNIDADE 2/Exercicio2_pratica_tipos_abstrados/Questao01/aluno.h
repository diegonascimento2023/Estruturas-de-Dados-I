#include <stdio.h>
typedef struct aluno Aluno;

/* Função que aloca dinamicamente uma estrutura Aluno, configurando seu 
nome e nota com valores passados como parâmetros*/
Aluno* aluno_cria(char* nome, float nota);

/*A função que libera o espaço em memória para a estrutura do tipo Aluno*/
void aluno_libera(Aluno* a);

/*A função que imprime na saída padrão os dados de um aluno*/
void aluno_imprime(Aluno* a);

/*A função que ordena em ordem alfabética um vetor de ponteiros para estruturas do tipo Aluno*/
void aluno_ordena(int n, Aluno** v); 

/*A função que salva em um arquivo texto os dados de um vetor de ponteiros 
para estruturas do tipo Aluno*/
void aluno_salva(FILE* fp, int n, Aluno** v);
