
typedef struct disciplina Disciplina;

/*Funçao que  aloca dinamicamente a estrutura do tipo Disciplina e retorna o seu endereço. Os campos 
nome e codigo são fornecidos como parâmetros.*/
Disciplina *criaDisciplina (char * nome, int codigo);

/* Função que libera o espaço alocado dinamicamente para a estrutura.*/
void exclui_disciplina (Disciplina* disciplina);