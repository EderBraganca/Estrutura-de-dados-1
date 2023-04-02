# ifndef arvore_h
# define arvore_h

typedef char TChave[200];

typedef struct {
  TChave chave;
} TItem;

typedef struct No {
  TItem item ;
  struct No *pEsq, *pDir ;
} TNo;

typedef struct{
    TNo *raiz;
}TArvore;

//Manter como especificado
void TArvore_Inicia (TNo **pRaiz);
//Definir de acordo com o metodo escolhido para insercao na arvore
int TArvore_Insere (TNo **ppRaiz, TItem x);
//Manter como especificado
TNo *TNo_Cria (TItem x);
//realizar o caminhamento adequado na arvore
void Central(TNo *p);


# endif