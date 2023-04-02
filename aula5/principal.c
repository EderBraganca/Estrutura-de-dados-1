#include "lista.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    TLista *original, *resultado, *auxiliar;
    char letra;
    TItem temp;

    //Inicialize as três listas
    TLista_Inicia(original);
    TLista_Inicia(resultado);
    TLista_Inicia(auxiliar);

    //le a linha da entrada
    while (scanf("%c", &letra) != EOF) {
          temp.letra = letra;
          TLista_InsereFinal(original, temp);
    }

    //analisa a lista original e coloca os caracteres na lista resultado ou auxiliar
    resolve(original, resultado, auxiliar);

    //imprime o resultado, caso a lista nao esteja vazia
    if(TLista_EhVazia(resultado))
      TLista_Imprime(resultado);
    else
      printf("\n");

    TLista_Esvazia(original);
    TLista_Esvazia(resultado);
    TLista_Esvazia(auxiliar);

    free(original);
    free(resultado);
    free(auxiliar);

    return 0;//nao remova
}
