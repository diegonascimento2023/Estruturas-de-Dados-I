#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contabancaria.h"


typedef struct contabancaria
{
    char titular[30];
    int numero;
    float saldo;
} ContaBancaria;

ContaBancaria *criaConta(char * titular, int numero, float saldo)
{
    ContaBancaria *contabancaria = (ContaBancaria *)malloc(sizeof(ContaBancaria));
    if (contabancaria == NULL)
    {
        printf("Memoria alocada com sucesso.\n");
        exit(1);
    }

    strcpy(contabancaria->titular, titular);
    contabancaria->numero = numero;
    contabancaria->saldo = saldo;

    return contabancaria;
}

void deposita(ContaBancaria *contabancaria, float deposito)
{
    contabancaria->saldo = contabancaria->saldo + deposito;
}

void saca(ContaBancaria *contabancaria, float saque)
{
    if (contabancaria->saldo > saque)
    {
        contabancaria->saldo = contabancaria->saldo - saque;
    
    }
    else
    {
        printf("Saldo insuficiente para realizar o saque.\n");
    }
}

void transfere(ContaBancaria *contabancaria1, ContaBancaria *contabancaria2, float valor)
{
    if (contabancaria1->saldo > valor)
    {   contabancaria1->saldo = contabancaria1->saldo - valor;
        contabancaria2->saldo = contabancaria2->saldo + valor;
        
    }
    else
    {
        printf("Saldo insuficiente para realizar a transferencia.\n");
    }
}

float saldo(ContaBancaria *contabancaria)
{

    return (contabancaria->saldo);
}

void libera(ContaBancaria *contabancaria)
{
    free(contabancaria);
}