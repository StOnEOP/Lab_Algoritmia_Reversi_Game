//
// Created by pedro on 07/05/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//
#include "estado.h"
#include "interpretador.h"
//
#include "etc.h"
#include "jogar.h"
#include "historico.h"
#include "sugest.h"

void sugestaoJogada(ESTADO e){ // recebe 1 estado que ja contem as jogadas validas e imprime um ponto onde elas se encontram
    // imprime a tabela valida
printf("\n\t1 2 3 4 5 6 7 8\n"
       "\t________________\n\n");
char c = ' ';
for (int i = 0; i < 8; i++) {
    printf("%d|\t",(i+1));
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
            case VALIDA:{
                c = '.';
                break;
                }
            }
            printf("%c ", c);
        }
    printf("\n");
    }

printf("\n");
}
