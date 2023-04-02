#ifndef prioridade_h
#define prioridade_h

struct team_t
{
    int id, pontos, pontosFavor, pontosContra;
    double saldo;
};

//Manter como especificado
struct team_t *alocaVetor(struct team_t *vetor, int n);
//Manter como especificado
struct team_t *desalocaVetor(struct team_t *vetor);
//Manter como especificado
void Heap_Refaz(struct team_t *heap, int esq, int dir);
//Manter como especificado
void Heap_Constroi(struct team_t *heap, int n);
//Manter como especificado
int compare(const struct team_t t1, const struct team_t t2);
//Manter como especificado
void Heap_Sort(struct team_t *heap, int n);
#endif
