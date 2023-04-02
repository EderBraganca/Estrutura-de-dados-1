#include <stdio.h>
#include <stdlib.h>
#include "duelo.h"

void liberaMemoria(Monstro *m){
    free(m);
}

void preencheVetor(Monstro *m, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &m[i].A);
        scanf("%d", &m[i].D);
        scanf("%d", &m[i].H);
    }
}

int podeInvocar(Monstro *m, int n){
    
    for(int contador = n; contador > 1; contador--){
        for (int i = contador; i > 1; i--)
        {   
            if(combinacao(m, i, contador, contador, 0, 0, 0) == 1)
                return 1;
        }
    }
    
    return 0;
}

int combinacao(Monstro *m, int nTermos, int contador, int i, int somaAtaque, int somaDefesa, int somaHabilidade){
    if(verificaInvocacao(m[0].A, somaAtaque, m[0].D, somaDefesa, m[0].H, somaHabilidade) == 1){
         return 1;
    }
    int auxA, auxB, auxC, auxD;

    if((nTermos > 1)&&(auxD > 1)){  
        if(i > 0){
            auxA = somaAtaque + m[i].A;
            auxB = somaDefesa + m[i].D;
            auxC = somaHabilidade + m[i].H; 
            auxD = nTermos; 
            
            if(verificaInvocacao(m[0].A, auxA, m[0].D, auxB, m[0].H, auxC) == 1){
                return 1;
            }
            return combinacao(m, auxD - 1, contador, i - 1, somaAtaque, somaDefesa, somaHabilidade);
        }
        return combinacao(m, nTermos - 1, contador - 1, i, somaAtaque, somaDefesa, somaHabilidade);
    }
    return 0;
}

int verificaInvocacao(int aP, int somaAtaque, int dP, int somaDefesa, int hP, int somaHabilidade){
    if(aP == somaAtaque){
        if(dP == somaDefesa){
            if (hP == somaHabilidade){
                return 1;
            }
        }
    }
    return 0;
} 