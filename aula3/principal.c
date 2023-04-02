#include "nota.h"
#include<stdio.h>

int main()
{
    //estrutura que mantem as notas e as duas medias
    struct nota notas;
    //leia as 4 primeiras notas
    lerNotas(&notas);
    //calcule a media das 4 primeiras notas
    calculaMedia(&notas);
    //se for o caso de exame
    if(notas.media > 5.0 && notas.media < 6.9){
      printf("\nAluno em exame.");
      //leia a nota do exame
      leExame(&notas);
      //calcule a nova media
      recalculaMedia(&notas);
      printf("\nNota do exame: %.1f", notas.notaExame);
      if (notas.mediaFinal >= 5.0)
        printf("\nAluno aprovado.");
      else
        printf("\nAluno reprovado.");
      //imprima o resultado de acordo com a primeira media e a segunda media
      printResultado(notas);
    }
    else if (notas.media > 7.0)
       printf("\nAluno aprovado.");
    else
      printf("\nAluno reprovado.");
    

    return 0;//nao remova
}
