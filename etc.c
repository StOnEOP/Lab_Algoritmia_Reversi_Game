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

VALOR inverte(VALOR p){
    printf("Entrou no inverte\n");
    if (p == VALOR_X) return VALOR_O;
    if (p == VALOR_O) return VALOR_X;
    else printf("ERROR: Inverso nao é possivel\n");
}

VALOR charToValor(char c){ // converte 1 char em Valor
    if( c =='O')    return VALOR_O;
    if( c =='X')    return VALOR_X;
    if( c =='-')    return VAZIA;
    if( c =='.')    return VALIDA;
    else printf("ERRO: charToValor INVALIDO!!\n");

}
char valorToChar(VALOR p){ // converte da variavel VALOR, para 1 char
    if (p == VALOR_O) return 'O';
    if (p == VALOR_X) return 'X';
    if (p == VAZIA)   return '-';
    else printf("ERROR: valorToChar INVALIDO!!\n");
}