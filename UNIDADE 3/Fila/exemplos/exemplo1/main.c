#include "fila.c"

int main() {
   
   Fila *Q = CriaFila(50);

    // Insere elementos na lista
    InsereFila(Q,10);
    InsereFila(Q,20);

    /*printf("Lista apos insercao de elementos:\n");
    lst2_imprime(lista2);
	printf("\n");*/


    // Comsultar elemento na lista
    int elem = 10;
    ConsultaFila(Q, &elem);

    // Remove um elemento da lista
    RemoveFila(Q, elem);


    // Libera a memória da lista
    DestruirFila(&Q);
    printf("Deu certo!\n");
    return 0;
}
