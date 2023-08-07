#include <stdio.h>
#include <stdlib.h>

typedef struct professor{
    char nome[30];
    char disciplinas[20];
    float horas;

}Professor;

int * preencha(int num_p){

   Professor * professor = (Professor *)malloc( num_p * sizeof(int));

    if ( professor == NULL){
        printf(" Memoria insuficiente.");
        exit (1);
      }  

    int i;
    for(i=0; i<num_p; i++){
      printf(" Digite o nome do professor.\n");
      scanf("%[^/n]", professor[i].nome);
      printf(" Digite a disciplina do professor\n");
      scanf("%[^/n]", professor[i].disciplinas); 
      printf(" Digite o regime de trabalho do professor(horas).\n");
      scanf("%d", &professor[i].horas); 
      
       

    }
         return 0;
}

  void imprima(int num_p){
   Professor * professor = (Professor *)malloc( num_p * sizeof(int));

    if ( professor == NULL){
        printf(" Memoria insuficiente.");
        exit (1);
    }
    int i;
    for(i=0; i<num_p; i++){
      printf(" Nome do professor: %s\n Disciplinas: %s\n Regime de trabalho: %d", professor[i].nome, professor[i].disciplinas, &professor[i].horas);
       }

}

int main(void){
    int num_p;
    printf("Digite o numero de professores a serem cadastrados.");
    scanf("%d", &num_p);

preencha( num_p );
imprima( num_p);
   
    
}