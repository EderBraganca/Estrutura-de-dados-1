# ifndef nota_h
# define nota_h

//COMPLETAR A ESTRUTURA
struct nota{
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float media;
    float notaExame;
    float mediaFinal;
};

//Manter como especificado
void lerNotas(struct nota *notas);
//Manter como especificado
void calculaMedia(struct nota *notas);
//Manter como especificado
void leExame(struct nota *notas);
//Manter como especificado
void recalculaMedia(struct nota *notas);
//Manter como especificado
void printResultado(struct nota notas);

# endif
