#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void lerOrdem(int *ordem){
    scanf("%d", ordem);
}

//manter como especificado
double **alocaMatriz(double **M, int ordem){
    M = malloc(ordem * sizeof(double));
    for (int i = 0; i < ordem; i++)
        M[i] = malloc(ordem * sizeof(double));
    return M;    
}

//manter como especificado
double **desalocaMatriz(double **M, int ordem){
    for (int i = 0; i < ordem; i++)
       free(M[i]);
    free(M); 
    return M;  
}

//manter como especificado
void lerOperacao(char *operacao){
    scanf(" %c", operacao);
}

void lerMatriz(double **M, int ordem){
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            scanf("%lf", &M[i][j]);
        }       
    }   
}

double somaMatriz(double **M, int ordem){
    double resultado = 0.0;
    int linha, min = 1, max = ordem - 1;

    for(linha = 0; linha < (ordem / 2) - 1; linha++){
        for(int coluna = min; coluna < max; coluna++)
        {
            resultado += M[linha][coluna];
        }
        max--;
        min++;
    }
    return resultado;
}

double media(double resultado, int ordem){
    double media = resultado /((ordem * ordem)/ 4.0 - ( ordem / 2.0));
    return media;
}

void printResultado(double resultado){
    printf("%.1lf", resultado);
}
