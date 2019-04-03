//
// Created by pja on 28/02/2019.
//
#include <stdio.h>
#include "estado.h"

ESTADO gInicial(ESTADO e, char peca, char modo){
    e.grelha [3][4] = VALOR_O;
    e.grelha [4][3] = VALOR_O;
    e.grelha [3][3] = VALOR_X;
    e.grelha [4][4] = VALOR_X;
    e.peca = peca;
    e.modo = modo;
    return e;
}

// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO e){
    printf("\n 1 2 3 4 5 6 7 8\n");

    char c = ' ';


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    c = 'O';
                    break;
                }
                case VALOR_X: {
                    c = 'X';
                    break;
                }
                case VAZIA: {
                    c = '-';
                    break;
                }
            }
            printf("%c ", c);

        }
        printf("\n");
    }

}

