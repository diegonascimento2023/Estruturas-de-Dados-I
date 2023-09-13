 #include <stdio.h>
 #include <stdlib.h>
 
 typedef struct retangulo
{
   float b;
   float h;
}Retangulo;

typedef struct lista
{
    Retangulo info;
    struct lista *prox;
}Lista;

static Lista* aloca(float b, float h){
Lista* p = (Lista*) malloc(sizeof(Lista));
p->info.b = b;
p->info.h = h;
p->prox = NULL;
return p;
}
