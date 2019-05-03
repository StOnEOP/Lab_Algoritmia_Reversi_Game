//
// Created by André Sousa on 2019-05-03.
//

#include "Andre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estado.h"
#include "interpretador.h"
#include "faria.h"

void pontos(ESTADO e){
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
                case VALIDA: {
                    c = '.';
                }

            }
            printf("%c ", c);

        }
        printf("\n");
    }
    printf("\n");

}