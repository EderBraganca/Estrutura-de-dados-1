#include <stdio.h>
#include <stdlib.h>
#include "presente.h"

int main(){
    int t;
    Gift temp;
    
    scanf("%d", &t);
    Gift *gifts;
    Kn *kn = malloc(t * sizeof(Kn));
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &kn[i].n, &kn[i].k);
        //ler os presentes, já calculando o volume
        gifts = readGifts(kn[i].n);
        //ordenar 
        quickSort(gifts, 0, kn[i].n - 1); 
        //imprime os menores valores
        print(gifts, kn[i].k, kn[i].n);  
        //libera a memoria 
        free(gifts);
    }  
    free(kn);
    return 0;
}