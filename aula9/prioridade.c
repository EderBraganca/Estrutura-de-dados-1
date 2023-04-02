#include "prioridade.h"
#include <stdio.h>
#include <stdlib.h>
//Manter como especificado
void Heap_Refaz(struct team_t *heap, int esq, int dir)
{
    int i = esq, j = i * 2 + 1;
    struct team_t aux = heap[i];

    while (j <= dir)
    {
        if (j < dir && compare(heap[j], heap[j + 1]))
            j++;
        if (compare(heap[j], aux))
            break;

        heap[i] = heap[j];
        i = j;
        j = i * 2 + 1;
    }
    heap[i] = aux;
}

//Manter como especificado
void Heap_Constroi(struct team_t *heap, int n)
{
    int esq = (n / 2) - 1;
    while (esq >= 0)
    {
        Heap_Refaz(heap, esq, n - 1);
        esq--;
    }
}

//Manter como especificado
struct team_t *alocaVetor(struct team_t *vetor, int n)
{
    vetor = (struct team_t *)malloc(n * sizeof(struct team_t));

    for (int i = 0; i < n; i++)
    {
        vetor[i].id = 0;
        vetor[i].pontos = 0;
        vetor[i].pontosContra = 0;
        vetor[i].pontosFavor = 0;
        vetor[i].saldo = 0;
    }

    return vetor;
}

//Manter como especificado
struct team_t *desalocaVetor(struct team_t *vetor)
{
    free(vetor);
    return NULL;
}

//Manter como especificado
void Heap_Sort(struct team_t *heap, int n)
{
    Heap_Constroi(heap, n);
    while (n > 1)
    {
        struct team_t aux = heap[n - 1];
        heap[n - 1] = heap[0];
        heap[0] = aux;
        n = n - 1;
        Heap_Refaz(heap, 0, n - 1);
    }
}

//Manter como especificado
int compare(const struct team_t t1, const struct team_t t2)
{
    if (t1.pontos > t2.pontos)
        return 1;
    else if (t1.pontos == t2.pontos){
        if (t1.saldo > t2.saldo)
            return 1;
        else if (t1.saldo == t2.saldo)
        {
            if (t1.pontosFavor > t2.pontosFavor)
                return 1;
            else if(t1.pontosFavor == t2.pontosFavor){
                if (t1.id < t2.id)
                    return 1;
                return 0;
                }
            return 0;
        }
        return 0;
    }
    return 0;
}