#include "presente.h"
#include <stdio.h>
#include <stdlib.h>

Gift* readGifts(int n)
{
    Gift *gifts = malloc(n * sizeof(Gift));

    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf %lf %lf", &gifts[i].i, &gifts[i].h, &gifts[i].w, &gifts[i].l);
        gifts[i].v = gifts[i].h * gifts[i].w * gifts[i].l;
    }
    return gifts;
}

void quickSort(Gift* gift, int n, int r){
    if(n < r){
        int i = partition(gift, n, r);
        quickSort(gift, n, i-1);
        quickSort(gift, i+1, r);
    }
}

int partition(Gift* gift, int n, int r){
    
    Gift x = gift[r]; 
    int i = n - 1;
    
    for(int j = n; j < r; j++){
        if((gift[j].v == x.v && gift[j].i > x.i)||(gift[j].v < x.v)){
            i++;
            switx(gift, j, i);
        }
    }
    switx(gift, i+1, r);

    return i + 1;
}

void quickSort2(Gift* gift, int n, int r){
    if(n < r){
        int i = partition2(gift, n, r);
        quickSort2(gift, n, i-1);
        quickSort2(gift, i+1, r);
    }
}

int partition2(Gift* gift, int n, int r){
    
    Gift x = gift[r]; 
    int i = n - 1;
    
    for(int j = n; j < r; j++){
        if(gift[j].i < x.i){
            i++;
            switx(gift, j, i);
        }
    }
    switx(gift, i+1, r);

    return i + 1;
}

int switx(Gift *gift, int n, int r){
    Gift temp = gift[n];
	gift[n] = gift[r];
	gift[r] = temp;
}

void print(Gift* gift, int k, int n){
    Gift *ordenedGifts = malloc(n * sizeof(Gift));

    for(int i = n-1, z = 0; z < k; i--, z++)
        ordenedGifts[z] = gift[i]; 

    quickSort2(ordenedGifts, 0, k - 1);

    for(int i = 0; i < k; i++){
        printf("%.0lf", ordenedGifts[i].i);
        if(i < k-1)
            printf(" ");
    }
    printf("\n");
    free(ordenedGifts);
}