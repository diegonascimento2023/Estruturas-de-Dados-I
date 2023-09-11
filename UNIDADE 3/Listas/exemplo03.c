#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Lista encadeada simples de frutas
struct frutas{
    char nome[10];//Nome da fruta
    struct frutas * proxima; //Endereço da proxima fruta
    float preco;
};

 struct futas * insere (struct frutas * fruta, char* nome, float* preco){
        struct frutas * novafruta = (struct frutas*) malloc(sizeof(struct frutas));
        strcpy(novafruta->nome, nome);
        novafruta->proxima = fruta;
        novafruta->preco = preco;
        

        return novafruta;
 }

int main(void){

   struct frutas *lista = NULL;
   lista = insere(lista, "maça");
   lista = insere(lista, "abacate");
    lista = insere(lista, "uva");
   
   free(lista);

return 0;
}