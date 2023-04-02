#include "prioridade.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int instancia = 1;
    //enquanto houver dados
    while (1)
    {
        int n;
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        struct team_t *heap = NULL;

        //leia o numero de times
        scanf("%d", &n);

        //se for zero, o programa acaba
        if (n == 0)
            return 0;
        if (instancia != 1)
        {
            printf("\n");
        }
        //aloque o heap
        heap = alocaVetor(heap, n);

        //calcula o numero de partidas
        npartidas = n * (n - 1) / 2;

        //para cada partida...
        for (i = 0; i < npartidas; ++i)
        {
            scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);

            heap[time1 - 1].pontosFavor += pontos1;
            heap[time1 - 1].pontosContra += pontos2;
            heap[time1 - 1].id = time1;
            heap[time2 - 1].pontosFavor += pontos2;
            heap[time2 - 1].pontosContra += pontos1;
            heap[time2 - 1].id = time2;

            if (pontos1 > pontos2)
            {
                heap[time1 - 1].pontos += 2;
                heap[time2 - 1].pontos += 1;
            }
            else
            {
                heap[time1 - 1].pontos += 1;
                heap[time2 - 1].pontos += 2;
            }
        }

        for (int i = 0; i < n; i++)
            heap[i].saldo = (heap[i].pontosFavor * 1.0) / (heap[i].pontosContra * 1.0);

        //ordenar os times
        Heap_Sort(heap, n);

        //imprima o resultado
        printf("Instancia %d\n", instancia);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", heap[i].id);
        }
        printf("\n");

        //desaloque o vetor
        heap = desalocaVetor(heap);
        instancia++;
    }

    return 0;
}
