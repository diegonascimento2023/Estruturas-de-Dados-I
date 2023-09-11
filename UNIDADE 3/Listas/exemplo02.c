#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Lista encadeada simples de frutas
struct frutas{
    char nome[10];//Nome da fruta
    struct frutas * proxima; //Endereço da proxima fruta
};

 
int main(void){
    struct frutas * fruta1  = malloc(sizeof(struct frutas));
    struct frutas * fruta2  = malloc(sizeof(struct frutas));
    struct frutas * fruta3  = malloc(sizeof(struct frutas));
//Inicializa os nomes da fruta
    strcpy(fruta1->nome, "maca");
    strcpy(fruta2->nome, "abacate");
    strcpy(fruta3->nome, "uva");
//faz o encadeamento dos espaços
    fruta1->proxima = fruta2;
    fruta2->proxima = fruta3;
    fruta3->proxima = NULL;

    struct frutas*p;
    for(p=fruta1; p!= NULL; p=p->proxima){
        printf("%s\n", p->nome);
    }

   

return 0;
}