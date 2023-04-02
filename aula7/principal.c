#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int n, *vetor;

	//le a entrada ate EOF
	while(scanf("%d", &n) != EOF)
	{
		vetor = alocaVetor(vetor, n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &vetor[i]);
		}
		
		ordena(vetor, n);

		int soma = 0;

		for(int i = 0, j = (n-1); i <( n / 2); i++, j--){
			soma += vetor[j] - vetor[i];
		}

		printf("%d\n", soma);
	}
	vetor = desalocaVetor(vetor);

  return 0;
}
