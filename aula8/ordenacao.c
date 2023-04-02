#include "ordenacao.h"
#include <stdlib.h>

//Manter como especificado
struct time *alocaVetor(struct time *vetor, int n)
{

    vetor = (struct time *)malloc(n * sizeof(struct time));

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
struct time *desalocaVetor(struct time *vetor)
{
    free(vetor);
    return NULL;
}

//implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
void ordenacao(struct time *vetor, int n, int r)
{
    if (n < r)
    {
        int i = partition(vetor, n, r);
        ordenacao(vetor, n, i - 1);
        ordenacao(vetor, i + 1, r);
    }
}

int partition(struct time *vetor, int n, int r)
{
    struct time x = vetor[r];
    int i = n - 1;

    for (int j = n; j < r; j++)
    {
        if (compare(vetor[j], x))
        {
            i++;
            switx(vetor, j, i);
        }
    }
    switx(vetor, i+1, r);

    return i + 1;
}

void switx(struct time *vetor, int n, int r)
{
    struct time temp = vetor[n];
    vetor[n] = vetor[r];
    vetor[r] = temp;
}

//compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const struct time t1, const struct time t2)
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
