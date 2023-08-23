/*Programa que utiliza o TAD ContaBancaria. */

#include <stdio.h>
#include "contabancaria.c"

int main(void)
{
  // Testa funçao cria conta
  ContaBancaria *conta1 = criaConta("Diego", 198, 1200);
  ContaBancaria *conta2 = criaConta("Joao", 198, 200);

  // Testa funçao transfere
  transfere(conta1, conta2, 50);

  //testa a funçao deposita
  deposita(conta2, 100);

  // Testa funçao saca
  saca(conta1, 100);

  // Chama a funçao saldo e armazena em uma variavel
  float saldoConta1 = saldo(conta1);
  float saldoConta2 = saldo(conta2);

  // Mostra o saldo das contas criadas após as operações
  printf(" Saldo conta 1: %f\n", saldoConta1);
  printf(" Saldo conta 2: %f\n", saldoConta2);

  // libera a memoria alocada para conta1
  libera(conta1);

  // libera a memoria alocada para conta1
  libera(conta2);

  return 0;
}
