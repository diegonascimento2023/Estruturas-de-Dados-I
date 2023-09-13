 #include "lista_dupla.h"


  struct lista2
{
	int info;// Armazena  um elemento do tipo inteiro na estrutura lista
    struct lista2 *ant;
	struct lista2 *prox;// Armazena o endereço do proximo elemento que será armazenado na estrutura lista
};

// função que cria uma lista vazia (NULL)
Lista2 *lst_cria(void)
{
	return NULL;// Retorna uma lista vazia
}

// função que insere um elemento no início da lista
Lista2 *lst2_insere(Lista2 *l, int v)//Recebe como parâmetro a lista do tipo Lista que irá receber o elemento do tipo inteiro que será inserido
{
	Lista2 *novo = (Lista2 *)malloc(sizeof(Lista2));//Aloca a memória dinamicamente para que o elementop seja inserido no espaço criado.
	if (novo == NULL)//Verifica se a memoria suficiente para alocar o espaço para "novo".
	{
		printf("[ERRO] memoria insuficiente!");//Exibe a mensagem de erro caso não tenha memmória sufiente.
		exit(1);//Aborta o programa
	}
	novo->info = v;// novo->info recebe o elemento v e armazena o elemento na struct lista
	novo->prox = l;// novo->prox recebe  o endereço da lista l e armazena o endereço do proximo elemento que será armazenado na estrutura lista. Dessa forma, "novo" passa a ser o novo elemento da lista l.
    novo->ant = NULL;

    if (l != NULL)//Verifica se a lista está vazia
	{
		l->ant = novo;
	}
	return novo;//Retorna a lista com o novo elemento e o endereço do proximo elemento que será inserido.

}

// função que busca um elemento na lista
Lista2 *lst2_busca(int elemento, Lista2 *l)// Recebe como parâmetro o elemento a ser buscado e em qual lista ele deve ser buscado
{
	Lista2 *p;//Criada a variável p do tipo lista para ser o contador do laço.
	for (p = l; p != NULL; p = p->prox)//O laço é iniciado quando o contador p recebe o endereço de l(o endereço do primeiro elemento da lista), logo em seguida verifica se p é diferente de NULL, se ele for diferente quer dizer que o endereço está preenchido, então ele compara se o elemento que está no endereço armazenado em p é  igual ao que foi recebido como parrâmetro, se for igual ele retorna o elemento presente no endereço de p, se for diferente p recebe o endereço do proximo elemento da lista.   
	
	{
		if (p->info == elemento)//Verifica se o elemento presente no endereço de p é igual ao elemento passado como parâmetro
			return p;
	}

	return NULL;//Retorna NULL se nenhum elemento presente na lista for igual ao elemento passado como parâmetro.
}

// função que retira um elemento da lista
Lista2 *lst2_retira(Lista2 *l, int elemento)// Recebe como parâmetro o elemento a ser retirado e em qual lista ele deve ser retirado
{
    Lista2 *p = lst2_busca(elemento, l);	  
	
	if (p == NULL)
    {
        return l;//não achou o elemento
    }
    
    /*retira o elemento do encadeamento*/
    if (l == p)/*Testa se é o primeiro elemento*/
    {
        return l;//não achou o elemento
    }
    else{
        p->ant->prox = p->prox;
    }
	
    if ( p->prox != NULL)/*testa se é o ultimo elemeento*/
    {
      p->prox->ant = p->ant;
    }
    
	free(p);
	return l;
}

// função que imprime os elementos da lista
void lst2_imprime(Lista2 *l)//Recebe como parâmetro o endereço da lista a ser impressa. Assim como, l representa o endereço  do primeiro elemento da lista.
{
	Lista2 *p;//Criada a variável p do tipo lista para ser o contador do laço.
	for (p = l; p != NULL; p = p->prox)//O laço é iniciado quando o contador p recebe o endereço de l(o endereço do primeiro elemento da lista), logo em seguida verifica se p é diferente de NULL, se ele for diferente quer dizer que o endereço está preenchido, então ele imprime o elemento que está no endereço e recebe o endereço do proximo elemento da lista. Após isso, ele faz novamente todo o processo  até encontrar um p igual a NULL, ou seja, o endereço está vazio e significa que  
	{
		printf("\tInfo = %d \n", p->info);//Exibe o elemento presente no endereço armazenado em p.
	}
}

// função que libera a memória alocada para a lista
void lst2_libera(Lista2 *l)// Recebe como parâmetro a lista que irá ter sua memória liberada 
{
	Lista2 *p = l; /* ponteiro para percorrer a lista*/
	Lista2 *t;/*Ponteiro auxiliar*/
	while (p != NULL)/* procura o final da lista, liberando a memoria alocada */
	{
		t = p->prox;//t recebe o endereço do proximo elemento
		free(p);//Libera a memoria alocada para p
		p = t;//p recebe o endereço do elemento sucessor de p
	}
}