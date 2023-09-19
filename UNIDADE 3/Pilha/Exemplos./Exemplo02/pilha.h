
typedef struct pilha Pilha;

// função que cria uma pilha
Pilha *pilha_cria(void);

// função que insere um elemento no início da pilha
void pilha_push(Pilha* p, int v);

// função que remove um elemento no início da pilha
int pilha_pop(Pilha* p);

// função que verifica se a pilha está vazia
int pilha_vazia(Pilha* p);

// função que libera a memória alocada para a pilha
void pilha_libera(Pilha* p);

// função que imprime pilha
void pilha_imprime(Pilha* p);
