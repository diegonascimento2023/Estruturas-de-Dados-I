#include <stdio.h>

/*#define true 1
#define false 0*/

/*
Enumeração (Enum):

enum bool {
    false,
    true
};
*/
enum boolean
{
    false,
    true
};
typedef enum boolean Bool;

int main(void)
{
    Bool val;
    printf(" Digite 0 ou 1\n");
    scanf("%d", &val);
    if (val == true)
    {
        printf("Verdadeiro");
    }
    else if (val == false)
    {
        printf("Falso");
    }
    else
    {
        printf("Erro");
    }
}