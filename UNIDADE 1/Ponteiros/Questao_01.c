/*Questão 1) Quais serão os valores de x, y e p ao final do trecho de código abaixo:
			OS VALORES DE X, Y E P, SÃO: X = 3; Y = 4; P = ENDEREÇO DE Y.
*/

#include <stdio.h>
int main(void)
{
	int x, y, *p;
	y = 0;
	p = &y;
	x = *p;
	x = 4;
	(*p)++;
	--x;
	(*p) += x;
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	printf("p: %p", p);
	return 0;
}