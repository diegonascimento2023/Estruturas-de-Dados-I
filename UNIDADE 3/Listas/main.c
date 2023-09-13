#include "lista_dupla.c"

int main() {
   
   Lista2 *lista2 = lst_cria();
    // Insere elementos na lista
    lista2 = lst2_insere(lista2, 1);
    lista2 = lst2_insere(lista2, 2);
    lista2 = lst2_insere(lista2, 3);
    lista2 = lst2_insere(lista2, 4);

    printf("Lista apos insercao de elementos:\n");
    lst2_imprime(lista2);
	printf("\n");



    // Busca um elemento na lista
    Lista2 *resultadoBusca = lst2_busca(3, lista2);
    if (resultadoBusca != NULL) {
        printf("Elemento %d encontrado na lista.\n", resultadoBusca->info);
    } else {
        printf("Elemento não encontrado na lista.\n");
    }
	printf("\n");

    // Remove um elemento da lista
    lista2 = lst2_retira(lista2, 4);
    printf("Lista apos a remocao do elemento %d:\n", 4);
    lst2_imprime(lista2);
	printf("\n");


    // Libera a memória da lista
    lst2_libera(lista2);


    return 0;
}
