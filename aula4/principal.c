#include "josephus.h"
#include<stdio.h>

int main()
{
    //NAO CRIE VARIAVEIS ADICIONAIS
    int n, k, resultado;

    scanf("%d %d", &n, &k);
    resultado = josephus(n, k);
    printf("Case 1: %d\n", resultado);

    return 0;//nao remova
}
