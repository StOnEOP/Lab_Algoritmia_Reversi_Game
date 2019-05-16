//
// Created by Pedro Faria - A72640 29/04/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
////
#include "estado.h"
#include "interpretador.h"
////
#include "etc.h"



void score(ESTADO e){    // diz a pontuação atual de cada jogador
    int o=0,x=0;
    for(int i=0;i<8;i++) {   // muda linha
        for (int j = 0; j < 8; j++) { // muda coluna
            if (e.grelha[i][j] == VALOR_X) x++;
            if (e.grelha[i][j] == VALOR_O) o++;
        }
    }
    printf("X -> %d \nO -> %d",x,o);
}

VALOR inverte(ESTADO e){
    printf("Entrou no inverte\n");
    if (e.peca == VALOR_X) return VALOR_O;
    if (e.peca == VALOR_O) return VALOR_X;
    else printf("ERROR: Inverso nao é possivel\n");
}