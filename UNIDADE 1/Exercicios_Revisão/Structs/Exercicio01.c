/*Programa para armazenar informações sobre diferentes tipos de frutas. Com uma struct chamada "Fruta" com os seguintes campos: nome (string), cor (string), sabor (string) e quantidade (int). Ele permite que usuário possa cadastrar várias frutas, armazenando-as em um vetor de structs. O programa contem as seguintes funcionalidades:

Cadastra uma nova fruta: Solicita ao usuário que insira o nome, cor, sabor e quantidade da fruta. Em seguida, adiciona a fruta ao array de structs.

Lista todas as frutas cadastradas: Imprimi na tela todas as informações das frutas cadastradas até o momento.

Busca fruta por nome: Solicita ao usuário que insira o nome de uma fruta.Ele busca no array de structs por todas as frutas com esse nome e imprimir suas informações.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fruta {
    char nome[50];
    char cor[20];
    int quantidade;
} Fruta;

// Função para cadastrar uma nova fruta
void cadastra(Fruta** frutas, int* numFrutas) {
    Fruta novaFruta;
    printf("Digite o nome da fruta: ");
    scanf("%s", novaFruta.nome);

    printf("Digite a cor da fruta: ");
    scanf("%s", novaFruta.cor);

    printf("Digite a quantidade da fruta: ");
    scanf("%d", &novaFruta.quantidade);

    (*numFrutas)++;
    *frutas = (Fruta*)realloc(*frutas, (*numFrutas) * sizeof(Fruta));
    (*frutas)[*numFrutas - 1] = novaFruta;

    printf("Fruta cadastrada com sucesso!\n");
}

// Função para listar todas as frutas cadastradas
void lista(const Fruta* frutas, int numFrutas) {
    if (numFrutas == 0) {
        printf("Nenhuma fruta cadastrada ainda.\n");
    } else {
        printf("\nLista de frutas cadastradas:\n");
        for (int i = 0; i < numFrutas; i++) {
            printf("Nome: %s\n", frutas[i].nome);
            printf("Cor: %s\n", frutas[i].cor);
            printf("Quantidade: %d\n\n", frutas[i].quantidade);
        }
    }
}

// Função de comparação de strings personalizada (substituindo strcmp)
int comparaStrings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Função para buscar uma fruta por nome
void buscaPorNome(const Fruta* frutas, int numFrutas) {
    char nomeBusca[50];
    printf("Digite o nome da fruta que deseja buscar: ");
    scanf("%s", nomeBusca);

    printf("Resultado da busca:\n");
    int encontrou = 0;
    for (int i = 0; i < numFrutas; i++) {
        // Usada a função compararStrings ao invés de strcmp
        if (comparaStrings(frutas[i].nome, nomeBusca) == 0) {
            printf("Nome: %s\n", frutas[i].nome);
            printf("Cor: %s\n", frutas[i].cor);
            printf("Quantidade: %d\n\n", frutas[i].quantidade);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma fruta encontrada com o nome: %s\n", nomeBusca);
    }
}



int main() {
    Fruta* frutas = NULL;
    int numFrutas = 0;
    int opcao;

    do {
        printf("Selecione a opcao:\n1. Cadastrar nova fruta\n2. Listar frutas cadastradas\n3. Buscar fruta por nome\n0. Sair\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastra(&frutas, &numFrutas);
                break;
            case 2:
                lista(frutas, numFrutas);
                break;
            case 3:
                buscaPorNome(frutas, numFrutas);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    free(frutas);
    return 0;
}
