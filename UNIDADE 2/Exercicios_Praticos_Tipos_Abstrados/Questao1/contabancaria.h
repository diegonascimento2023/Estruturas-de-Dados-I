

typedef struct contabancaria ContaBancaria;

/*Funçao que aloca dinamicamente uma srtuct conta bancaria e retorna seu endereço.
Os parametros são: titular, numero e saldo.*/
ContaBancaria *criaConta(char * titular, int numero, float saldo);

/*  Função que recebe, como parâmetros, o endereço de uma estrutura do tipo
ContaBancaria e um valor, atualizando o saldo*/
void deposita(ContaBancaria *contabancaria, float deposito);

/* Função que recebe, como parâmetros, o endereço de uma estrutura do tipo ContaBancaria e
um valor, atualizando o saldo. Verificar se o saldo é suficiente para realizar o saque.*/
void saca(ContaBancaria *contabancaria, float saque);

/*Funçao que recebe, como parâmetros, os endereços das estruturas do tipo
ContaBancaria e um valor, atualizando os saldos. Verificar se o saldo é suficiente para
realizar a transferência.*/
void transfere(ContaBancaria *contabancaria1, ContaBancaria *contabancaria2, float valor);

/*Função que recebe o endereço de uma estrutura do tipo ContaBancaria e retorna seu saldo*/
float saldo(ContaBancaria *contabancaria);

/* Função que libera o espaço alocado dinamicamente para a estrutura.*/
void libera(ContaBancaria *contabancaria);