# ifndef lista_h
# define lista_h

//MANTER COMO ESPECIFICADO
typedef struct {
    char letra;
} TItem;

//MANTER COMO ESPECIFICADO
typedef struct celula {
    struct celula *pProx;
    TItem item;
} TCelula;

//MANTER COMO ESPECIFICADO
typedef struct {
    TCelula *pPrimeiro, *pUltimo;
} TLista;

//MANTER COMO ESPECIFICADO

//Inicializa a lista
void TLista_Inicia(TLista *pLista);
//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista);
// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x);
// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX);
// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista);
// Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista);
// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_Include(TLista *pLista1, TLista *pLista2);
//analisa a lista original e coloca os caracteres na lista resultado ou auxiliar
void resolve(TLista *original, TLista *resultado, TLista *auxiliar);
# endif
