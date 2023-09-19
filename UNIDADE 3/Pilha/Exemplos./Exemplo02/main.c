#include "pilha.c"

int main() {
   
   Pilha *pilha1 = pilha_cria();
   
    // Insere elementos na lista
     pilha_push(pilha1, 2.1);
    pilha_push(pilha1, 2.2);
    pilha_push(pilha1, 2.3);
    pilha_push(pilha1, 2.4);
     pilha_push(pilha1, 2.5);

    printf("Pilha apos insercao de elementos:\n");
    pilha_imprime(pilha1);
	printf("\n");


    // Remove um elemento da lista
    pilha_pop(pilha1);
    printf("Pilha apos a remocao do elemento.\n");
    pilha_imprime(pilha1);
	printf("\n");


    // Libera a memória da pilha
     pilha_libera(pilha1);


    return 0;
}