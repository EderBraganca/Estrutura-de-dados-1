#include "ordenacao.h"
#include <stdio.h>

int main()
{
    int instancia = 1;
    //enquanto houver dados
    while (1)
    {
        int n;
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        struct time *vetor = NULL;

        //leia o numero de times
        scanf("%d", &n);

        //se for zero, o programa acaba
        if (n == 0)
            return 0;
        if (instancia != 1)
        {
            printf("\n");
        }

        //aloque o vetor
        vetor = alocaVetor(vetor, n);

        //calcula o numero de partidas
        npartidas = n * (n - 1) / 2;

        //para cada partida...
        for (i = 0; i < npartidas; ++i)
        {
            scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);

            vetor[time1 - 1].pontosFavor += pontos1;
            vetor[time1 - 1].pontosContra += pontos2;
            vetor[time1 - 1].id = time1;
            vetor[time2 - 1].pontosFavor += pontos2;
            vetor[time2 - 1].pontosContra += pontos1;
            vetor[time2 - 1].id = time2;

            if (pontos1 > pontos2)
            {
                vetor[time1 - 1].pontos += 2;
                vetor[time2 - 1].pontos += 1;
            }
            if (pontos1 <= pontos2)
            {
                vetor[time1 - 1].pontos += 1;
                vetor[time2 - 1].pontos += 2;
            }
        }
        //estabelecendo o saldo final

        for (int i = 0; i < n; i++)
            vetor[i].saldo = (vetor[i].pontosFavor * 1.0) / (vetor[i].pontosContra * 1.0);

        //ordenar os times
        ordenacao(vetor, 0, n - 1);

        //imprima o resultado
        printf("Instancia %d\n", instancia);
        for (int i = 0; i < n; i++){
            printf("%d ", vetor[i].id);
        }
        printf("\n");

        //desaloque o vetor
        vetor = desalocaVetor(vetor);
        instancia++;
    }

    return 0;
}
