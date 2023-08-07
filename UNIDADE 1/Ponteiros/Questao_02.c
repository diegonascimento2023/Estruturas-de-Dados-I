/*Questão 2) Considere o trecho de código abaixo:

int main(void) {
int x, *p;
x = 100;
p = x;
printf(“Valor de p = %p\tValor de *p = %d”, p, *p);

Se tentarmos compilar o programa (não o compile ainda), você acha que o compilador nos
fornece alguma mensagem? Se sim, responda:
a) Esta mensagem é de erro ou advertência?
  ERRO

b) Por que o compilador emite tal mensagem?
  PORQUE NA LINHA 4 DO CÓDIGO É NECESSARIO ADICIONAR O “&” ANTES DO X, PARA QUE “P” APONTE PARA A VARIAVEL X.

c) Compile e execute o programa. A execução foi bem sucedida?
  SIM

d) Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida pelo compilador.

e) Compile e execute novamente o programa. A execução foi bem sucedida?
  SIM*/

#include <stdio.h>

int main(void)
{
    int x, *p;
    x = 100;
    p = &x;
    *p = x;
    printf("Valor de p = %p\tValor de *p = %d", p, *p);
}