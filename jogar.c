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
#include "check.h"



ESTADO jogar(ESTADO e,int linha,int coluna) {
    //if (isOver == 1) printf("Jogo Terminado\n"); // se jã nao houver jogadas possiveis
    /*else*/ if(jogadaValida(e,linha,coluna)) { // se a jogada for valida
            e.grelha[linha][coluna] = e.peca;   // poe a peça na coordenada selecionada
            e=virapecas(e,linha,coluna);        // vira as peças apartir da coordenada
            addHjogada(e.peca,linha,coluna);    // adiciona a jogada ao historico
            e.peca=inverte(e.peca);                  // inverte a peça para o proximo jogador
         } else printf("Jogada Invalida\n");

        return e;


}

int jogadaValida(ESTADO e, int linha,int coluna){
    if(linha>=0 && linha <8 && coluna >=0 && coluna < 8 && e.grelha[linha][coluna]==VAZIA && check(e,linha,coluna) != 0){
        return 1;
    }else return 0;
}

