#include "pilha.h"
#include <stdio.h>

int main()
{
        Pilha estacionamento;
        Item item;
        int i, n, k, max, c, s, erro = 0, tamanho = 0;

        //armazena as entradas no estacionamento, a cada instante de tempo
        int entrada[50600] = {0};
        //armazena as saidas no estacionamento, a cada instante de tempo
        int saida[50600] = {0};

        //inicializar a pilha
        Pilha_Inicia(&estacionamento);

        //ler os valores de n e k
        scanf("%d %d", &n, &k);

        //para cada carro, ler os horarios de entrada e de saida
        for(i = 0;i < n; i++){
            scanf("%d %d", &c, &s);

            //armazena o horario maximo de saida
            if(i == 0 || s > max)
                max = s;

            //marca nos horarios de entrada e de saida que ha um carro naquele instante
            //entrando no tempo c
            entrada[c] = c;
            //e saindo no tempo s
            saida[s] = c;
        }

        //simula o estacionamento ate o ultimo horario
        for(i = 1; i <= max; i++){
            //se o i-esimo horario tiver a saida de algum carro
            if(saida[i] != 0) {
                //se a pilha NAO estiver vazia e o carro no topo da pilha for igual ao que tem que sair no instante indicado por saida[i]
                //PREENCHER AQUI
                if(!Pilha_EhVazia(&estacionamento) && Pilha_Top(&estacionamento) == saida[i])
                {
                    //remover da pilha
                    Pilha_Pop(&estacionamento, &item);
                    //decrementar o contador de tamanho da pilha
                    tamanho--;
                }
                //caso contrario, deu erro e ja pode parar
                else {
                    erro = 1;
                    break;
                }
            }
            //se o i-esimo horario tiver a entrada de algum carro
            if(entrada[i] != 0){
              //verifica se há vaga no estacionamento
                if(tamanho < k)
                {
                  //cria um item com o valor de entrada[i]
                  item.carro = entrada[i];
                  //adiciona o carro na pilha
                  Pilha_Push(&estacionamento, item);
                  //incrementa o contador de tamanho da pilha
                  tamanho++;
                }
                //caso contrario, deu erro e ja pode parar
                else {
                    erro = 1;
                    break;
                }
            }
        }

        //imprime a saida de acordo com a ocorrencia ou nao de erro
        if (erro != 0)
            printf("Nao");
        else
            printf("Sim");

        //esvazia a pilha do estacionamento
        Pilha_Esvazia(&estacionamento);

        return 0;//nao remova
}
