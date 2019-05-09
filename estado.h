#ifndef PROJ_ESTADO_H
#define PROJ_ESTADO_H
#define  MAX_BUF 1024


/**
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/



typedef enum {VAZIA, VALOR_X, VALOR_O,VALIDA} VALOR;

/**
Estrutura que armazena o estado do jogo
*/
typedef struct estado {
    VALOR peca;
    VALOR grelha[8][8];
    char modo; // modo em que se está a jogar! M-> manual, A-> contra computador
} ESTADO;

ESTADO gInicial(ESTADO e, char peca, char modo);
void printa(ESTADO);


#endif