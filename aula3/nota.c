#include "nota.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void lerNotas(struct nota *notas){
    scanf("%f %f %f %f", &notas->nota1, &notas->nota2, &notas->nota3, &notas->nota4);
}

void calculaMedia(struct nota *notas){
    notas->media = ((notas->nota1 * 2.0) + (notas->nota2 * 3.0) + (notas->nota3 * 4.0) + (notas->nota4 * 1.0)) / 10.0; 
    printf("Media: %.1f", notas->media);
}

void leExame(struct nota *notas){
    scanf("%f", &notas->notaExame);
}

void recalculaMedia(struct nota *notas){
    notas->mediaFinal = (notas->media + notas->notaExame) / 2.0;
}

void printResultado(struct nota notas){
    printf("\nMedia final: %.1f", notas.mediaFinal + 0.001);
}
