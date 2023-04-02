# ifndef pilha_h
# define pilha_h

typedef struct {
    int carro;
} Item;

typedef struct celula {
    struct celula *prox;
    Item item;
} Celula;

typedef struct {
    Celula *cabeca;
} Pilha;

//Inicializa a pilha
void Pilha_Inicia(Pilha *pilha);
//Retorna se a pilha esta vazia
int Pilha_EhVazia(Pilha *pilha);
// Insere um item no inicio da pilha
int Pilha_Push(Pilha *pilha, Item item);
// Retira o primeiro item da pilha
int Pilha_Pop(Pilha *pilha, Item *item);
// Retorna o primeiro item da pilha
int Pilha_Top(Pilha *pilha);
// Remove cada elemento de uma pilha e libera a memória
void Pilha_Esvazia(Pilha *pilha);
# endif
