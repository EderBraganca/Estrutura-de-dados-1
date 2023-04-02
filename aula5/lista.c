#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {
    pLista->pPrimeiro = (TCelula*) malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
        //alterei do original da aula
        return (pLista->pPrimeiro == pLista->pUltimo);
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {
  pLista->pUltimo->pProx = (TCelula*) malloc(sizeof(TCelula));
  pLista->pUltimo = pLista->pUltimo->pProx;
  pLista->pUltimo->item = x;
  pLista->pUltimo->pProx = NULL;
  return 1;
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
  if(TLista_EhVazia(pLista))
    return 0;

  TCelula *pAux;
  pAux = pLista->pPrimeiro->pProx;
  *pX = pAux->item;
  pLista->pPrimeiro->pProx = pAux->pProx;
  free(pAux);
  return 1;
}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {
  
  TCelula *celulaAtual = pLista->pPrimeiro->pProx;

  while(celulaAtual != pLista->pUltimo) {
        printf("%c ", celulaAtual->item.letra);
        celulaAtual = celulaAtual->pProx;
  }
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
  TCelula* atual = pLista->pPrimeiro;
  while(atual != NULL){
        TCelula *pAux = atual->pProx;
        free(atual);
        atual = pAux;
    }
}

// Acrescenta o conteudo de uma lista no inicio de outra, apenas manipulando ponteiros
void TLista_Include(TLista *pLista1, TLista *pLista2){
    pLista1->pUltimo->pProx = pLista2->pPrimeiro;
}

//MANTER COMO ESPECIFICADO
//analisa a lista original e coloca os caracteres na lista resultado ou auxiliar
void resolve(TLista *original, TLista *resultado, TLista *auxiliar){

  int flag = 0;
  TCelula *pAux;
  TItem temp;

  //percorre a lista original, caractere por caractere
  pAux = original->pPrimeiro->pProx;
  while (pAux->pProx != NULL) {
          //se o caractere for ']' então incluir os caracteres da lista auxiliar na lista resultado
          if(pAux->item.letra == ']' || pAux->item.letra == '['){
            if (flag == 1)
            {
              //a flag deve indicar que "End" foi pressionado
              flag = 0;
              //se a lista auxiliar nao estiver vazia
              if(!TLista_EhVazia(auxiliar)){
                //incluir o conteudo da lista auxiliar na lista de resultado
                TLista_Include(resultado, auxiliar);
                //iniciar os ponteiros da lista auxiliar novamente
                TLista_Inicia(auxiliar);
              }
            }
          }

          // se ler o caractere '[', a flag deve indicar que "Home" foi pressionado
          if(pAux->item.letra == '['){
            flag = 1;
          }

          //se ler um caractere sem "Home" ter sido pressionado, inserir direto no final da lista de resultado
          if(pAux->item.letra != '[' && pAux->item.letra != ']' && flag == 0){
            temp.letra = pAux->item.letra;
            TLista_InsereFinal(resultado, temp);
          }
          //se ler um caractere com "Home" tendo sido pressionado, inserir na lista auxiliar
          else if(pAux->item.letra != '[' && pAux->item.letra != ']' && flag == 1){
            temp.letra = pAux->item.letra;
            TLista_InsereFinal(auxiliar, temp);
          }
          // vai para a proxima celula
          pAux = pAux->pProx;
    }

    //processa os ultimos caracteres mesmo que nao haja "Home" ou "End" no final da entrada
    if (flag == 1)
    {
      //se a lista auxiliar nao estiver vazia
      if(!TLista_EhVazia(auxiliar)){
        //incluir o conteudo da lista auxiliar na lista de resultado
        TLista_Include(resultado, auxiliar);
      }
    }
}
