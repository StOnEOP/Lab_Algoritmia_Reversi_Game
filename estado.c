//
// Created by pja on 28/02/2019.
//
#include <stdio.h>
#include "estado.h"

ESTADO gInicial (ESTADO e, char peca, char modo){
    for(int x=0;x<8;x++)
        for(int y=0;y<8;y++){
            e.grelha[x][y] = VAZIA;
        }
    e.grelha [3][4] = VALOR_O;
    e.grelha [4][3] = VALOR_O;
    e.grelha [3][3] = VALOR_X;
    e.grelha [4][4] = VALOR_X;
    e.peca = peca;
    e.modo = modo;
    return e;
}


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



