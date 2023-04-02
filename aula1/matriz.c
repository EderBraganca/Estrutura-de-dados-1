#include "matriz.h"
#include<stdio.h>

void lerOperacao(char *operacao){
    scanf("%c", operacao);
}

void lerMatriz(double M[][12]){
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            scanf("%lf", &M[i][j]);
        }       
    }    
}

double somaMatriz(double M[][12]){
    double resultado = 0.0;
    int linha, min = 1, max = 11;

    for(linha = 0; linha < 5; linha++){
        for(int coluna = min; coluna < max; coluna++)
        {
            resultado += M[linha][coluna];
        }
        max--;
        min++;
    }
    return resultado;
}

double media(double resultado){
    double media = resultado / 30.0;
    return media;
}

void printResultado(double resultado){
    printf("%.1lf", resultado);
}
