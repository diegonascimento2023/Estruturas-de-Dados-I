#include <stdio.h>
#include <stdlib.h>

// Função que recebe duas strings como entrada e retorna uma nova string que é a concatenação das duas.
char * concatenacao(char * string1, char * string2, int tam) {
    char * string_concatenada = (char *) malloc((tam * 2 + 2) * sizeof(char)); // +1 para o caractere nulo '\0'
    if (string_concatenada == NULL) {
        printf("Memória insuficiente!");
        exit(1);
    }
    
    int i;
    for (i = 0; i < tam; i++) {
        string_concatenada[i] = string1[i];
    }
    for (; i < (tam * 2) + 1; i++) {
        string_concatenada[i] = string2[i - tam];
    }
    string_concatenada[ (tam * 2) + 1] = '\0'; // Adiciona o caractere nulo ao final da string
    
    return string_concatenada;
}

//Funçao main apenas para mostrar se a funçao concatenacao realmente funciona.
int main(void) {
    int i, tam = 3;
    char string1[3] = {"Bom"};
    char string2[4] = {" dia"};
    
    char * string_concatenada = concatenacao(string1, string2, tam);
    for (i = 0; i < (tam * 2) + 1; i++) {
        printf("%c", string_concatenada[i]);
    }
    printf("\n");
    
    free(string_concatenada); // Liberar a memória alocada para a string concatenada
    
    return 0;
}
