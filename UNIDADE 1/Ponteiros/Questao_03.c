/*Questão 3) Qual será a saída exibida pelo programa a seguir:
#include <stdio.h>
int main(void) {
int a, b, c, d;
int *p1;
int *p2 = &a;
int *p3 = &c;
p1 = p2;
*p2 = 10;
b = 20;
int **pp; pp = &p1;
*p3 = **pp;
int *p4 = &d;
*p4 = b + (*p1)++; printf("%d\t%d\t%d\t%d\n", a, b, c, d);
return 0;


Observe que, se int *p é uma variável do tipo ponteiro para inteiro, então int **pp é uma variável do tipo ponteiro para ponteiro de inteiro, isto é, uma varável que poderá armazenar o endereço de um ponteiro do tipo int.
A SAIDA SERÁ OS VALORES DE A, B, C E D, QUE SÃO RESPECTIVAMENTE, 11, 20, 10 E 30. */

#include <stdio.h>
int main(void)
{
    int a, b, c, d;
    int *p1;
    int *p2 = &a;
    int *p3 = &c;
    p1 = p2;
    *p2 = 10;
    b = 20;
    int **pp;
    pp = &p1;
    *p3 = **pp;
    int *p4 = &d;
    *p4 = b + (*p1)++;
    printf("%d\t%d\t%d\t%d\n", a, b, c, d);
    return 0;
}