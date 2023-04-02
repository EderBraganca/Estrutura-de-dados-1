#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
void TArvore_Inicia(TNo **pRaiz)
{
  *pRaiz = NULL;
}

//Manter como especificado
int TArvore_Insere(TNo **ppRaiz, TItem x)
{
  TNo **ppAux = ppRaiz;

  while (*ppAux != NULL)
  {
    int i = 0;
    for (; (x.chave[i] == (*ppAux)->item.chave[i]); i++);

    if (x.chave[i] < (*ppAux)->item.chave[i] && (i < strlen(x.chave) || i < strlen((*ppAux)->item.chave)))
      ppAux = &((*ppAux)->pEsq);
    else if (x.chave[i] > (*ppAux)->item.chave[i] && (i < strlen(x.chave) || i < strlen((*ppAux)->item.chave)))
      ppAux = &((*ppAux)->pDir);
    else 
      return 0;
  }
  *ppAux = TNo_Cria(x);
  return 1;
}

//Manter como especificado
TNo *TNo_Cria(TItem x)
{
  TNo *pAux = (TNo *)malloc(sizeof(TNo));
  pAux->item = x;
  pAux->pEsq = NULL;
  pAux->pDir = NULL;
  return pAux;
}

//realizar o caminhamento adequado na arvore
void Central(TNo *p)
{
  if (p == NULL)
    return;
  Central(p->pEsq);
  printf("%s\n", p->item.chave);
  Central(p->pDir);
}