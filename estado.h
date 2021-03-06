//
// Created by pja on 27/02/2019.
//



#ifndef PROJ_ESTADO_H
#define PROJ_ESTADO_H
#define  MAX_BUF 1024


/**
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/


// definição de valores possiveis no tabuleiro
typedef enum {VAZIA, VALOR_X, VALOR_O, VALIDA, SUGESTAO} VALOR;

/**
Estrutura que armazena o estado do jogo
*/
typedef struct estado {
    VALOR peca; // peça do jogador que vai jogar!
    VALOR grelha[8][8];
    char modo; // modo em que se está a jogar! M-> manual, A-> contra computador
    int nivel;  //nivel do bot, 0 caso nao exista
    VALOR pecaBot;  //peca da AI, 0 caso esteja em jogo manual
} ESTADO;

ESTADO gInicial(ESTADO e, VALOR peca, char modo);
void printa(ESTADO);


#endif //PROJ_ESTADO_H