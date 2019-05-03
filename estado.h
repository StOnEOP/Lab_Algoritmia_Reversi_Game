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
    char modo; // modo em que se está a jogar! 0-> manual, 1-> contra computador
} ESTADO;

ESTADO gInicial(ESTADO e, char peca, char mod);
void printa(ESTADO);


#endif