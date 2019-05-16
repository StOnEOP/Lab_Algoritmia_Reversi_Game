//
// Created by pja on 28/02/2019.
//
#include <stdio.h>
#include "estado.h"
#include "files.h"

ESTADO gInicial (ESTADO e, char peca, char modo){
    for(int x=0;x<8;x++)
        for(int y=0;y<8;y++){
            e.grelha[x][y] = VAZIA;
        }
    e.grelha [3][4] = VALOR_X;
    e.grelha [4][3] = VALOR_X;
    e.grelha [3][3] = VALOR_O;
    e.grelha [4][4] = VALOR_O;
    e.peca = peca;    // aqui e.peca é char? mas na def de estado é Valor, envio 1 valor para 1 char?
    e.modo = modo;
    return e;
}

// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO e){
    printf("\n\t1 2 3 4 5 6 7 8\n"
           "\t________________\n\n");

    char c = ' ';
    for (int i = 0; i < 8; i++) {
        printf("%d|\t",(i+1));        // imprime a label á esquerda
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
                case VALIDA:{ // adicionado caso seja valida
                    c= '.';
                    break;
                }
            }
            printf("%c ", c);

        }
        printf("\n");
    }
    printf("\n");

}

