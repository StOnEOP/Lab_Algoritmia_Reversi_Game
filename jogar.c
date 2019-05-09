//
// Created by Pedro Faria - A72640 02/05/2019.
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

void jogar(ESTADO e,int l,int c){ // verifica se a jogada é valida e joga-a
    int linha  = l-1;   //Arrays começam em zero
    int coluna = c-1;
    if (jogadaValida(e,linha,coluna) == 1){ // se a jogada for valida
        virarPecas(linha,coluna); // vira as peças em todas as direções possiveis ///tens discuçao sobre esta funçao no GitHub///
        addHjogada(linha,coluna); // adiciona essa jogada ao historico { Lista ligada}
    }
    else printf("ERRO jogar()\n");          // TESTE
}

int jogadaValida(ESTADO e, int linha, int coluna){ // 1 == verdade 0== falso
    if (linha >7 || linha < 0 || coluna >7 || coluna <0) return 0; // se o local for fora do tabuleiro a jogada não é valida
        // verifica se há outra peça igual a da jogada horizontalmente, verticalmente e em ambas as diagonais, caso 1 delas exista a jogada é valida, logo retorna True
    else if ((checkHorizontal(e,linha,coluna) == 1) ) {printf("valida é verdade\n");return 1;} //TESTE
         else {printf("NAO E VALIDA \n");return 0;}// caso nenhuma das funçoes anteriores dê verdade, significa que a nao há jogadas validas
}

//void virarPecas(ESTADO e,int linha,int coluna){}
