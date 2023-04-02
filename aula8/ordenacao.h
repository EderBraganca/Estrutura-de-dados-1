# ifndef ordenacao_h
# define ordenacao_h

struct time {
    int id, pontos, pontosFavor, pontosContra; 
    double saldo;
};

//Manter como especificado
void ordenacao(struct time *vetor, int n, int r);
//Manter como especificado
struct time *alocaVetor(struct time *vetor, int n);
//Manter como especificado
struct time *desalocaVetor(struct time *vetor);
//faz a comparacao utilizada para ordenar os times
int compare(struct time t1, struct time t2);
//Necessário para o metodo de ordenação quickSort
int partition(struct time *vetor, int n, int r);
//método de troca
void switx(struct time *vetor, int n, int r);
# endif
