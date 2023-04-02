#include <stdio.h>
#include <stdlib.h>
#include "duelo.h"

int main(){
    int n;
    
    scanf("%d", &n);
    Monstro *monstros = malloc((n + 1) * sizeof(Monstro));
    
    preencheVetor(monstros, n+1);

    if(podeInvocar(monstros, n) == 1)
        printf("Y");
    else    
        printf("N");

    free(monstros);
    return 0;
}