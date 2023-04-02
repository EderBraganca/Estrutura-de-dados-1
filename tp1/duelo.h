#ifndef duelo_h
    #define duelo_h

    typedef struct{
        int A;
        int D;
        int H;
    }Monstro;

    int podeInvocar(Monstro *m, int n);
    void liberaMemoria(Monstro *m);
    void preencheVetor(Monstro *m, int n);
    int verificaInvocacao(int aP, int somaAtaque, int dP, int somaDefesa, int hP, int somaHabilidade);
    int combinacao(Monstro *m, int nTermos, int contador, int i, int somaAtaque, int somaDefesa, int somaHabilidade);
#endif