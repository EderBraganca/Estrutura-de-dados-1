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
    int min = 1, max = 1;

    for(int linha = 0; linha < 6; linha++){
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

int main()
{
    double M[12][12], resultado;
    char operacao;

    lerOperacao(&operacao);
    lerMatriz(M);
    resultado = somaMatriz(M);

    if(operacao == 'M')
      resultado = media(resultado);

    printResultado(resultado);

    return 0;//nao remova
}
