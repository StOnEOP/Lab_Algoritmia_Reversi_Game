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
#include "validas.h"
#include "etc.h"
#include "bot.h"
#include "check.h"

int peso[8][8]={
        {99,-8, 8, 6, 6, 8, -8, 99},
        {-8,-24,-4,-3,-3,-4,-24,-8},
        {8, -4, 7, 4, 4, 7, -4, 8},
        {6, -3, 4, 0, 0, 4, -3, 6},
        {6, -3, 4, 0, 0, 4, -3, 6},
        {8, -4, 7, 4, 4, 7, -4, 8},
        {-8,-24,-4,-3,-3,-4,-24,-8},
        {99,-8, 8, 6, 6, 8, -8, 99}
}; // cria a tabela de pesos

ESTADO bot(ESTADO e, char peca){    //gamestate, peca do bot, nivel do bot
    VALOR pecaBot = charToValor(peca);
    VALOR pecaPc = inverte(pecaBot);
    e.peca= VALOR_X;
    while (isOver(e) != 1) {                //enquanto nao se chegar ao fim do jogo, ie, já nao ha mais jogadas
        while (validasJogada(e) != 0) {     //enquanto houver jogadas validas para a peça atual
            if (e.peca == pecaBot) {
                e = jogaBot(e);

            } else if(e.peca== pecaPc) {
                e = jogaPlayer(e);

            }
        }
    }

}

ESTADO jogaBot (ESTADO e){
    int bLinha; int bColuna;          //coordenadas para depois receber a jogada do bot
    selectJogada(e,*bLinha,*bColuna);   // seleciona a jogada dependendo da dificuldade
    e=jogar(e,bLinha,bColuna);          // joga na coordenada selecionada
    e.peca = inverte(e.peca);           // muda a peça para o proximo jogador
    return e;
}

int selectJogada (ESTADO e, int *bLinha, int *bColuna){     // envia 1 estado,e 2 variaveis, para depois receber coordenadas nessas variaveis
    /*
     * TODO:
     * procurar de todas as VALIDAS, a que tem melhor score. logo temos de adicionar o score as validas
     */
    int tmp=0;int res=0;
    for (int i = 0; i <8 ; ++i) {
        for (int j = 0; j < ; ++j) {
                tmp = checkScore(e,i,j); //guarda o score da mesma numa variavel
                if (tmp == res){
                    res = aleatorio(tmp,res); //seleciona 1 de forma aleatoria
//Nao passa a linha e coluna. Logo é melhor quando forem igual fica o res ie, apagar este if
                }
                if (tmp>res) {
                    res=tmp;
                    bLinha = i;
                    bColuna= j;
                }

            }
        }
    return 0;
}


int checkScore(ESTADO e,int i,int j){ //recebe 1 coordenada e devolve o score da mesma usando minmax com o e.nivel
    int r=0;
    switch (e.nivel){
        case 1:
            r=  (- (check(e,i,j)) + - (peso[i][j]));    // ira escolher sempre o pior score, pois caso de 30 de score, r devolvera -30, mas caso receba 1, devolvera -1 e -1> -30
            break;
        case 2:
            r= check(e,i,j);                            // melhor jogada sem considerar o peso da posiçao
            break;
        case 3:
            r=(check(e, i, j) + peso[i][j]);            // melhor jogada na melhor posiçao
            break;
        case 0:
            r=(check(e, i, j) + peso[i][j]);            // melhor jogada na melhor posiçao para jogo em modo manual
            break;
    }
    return r;
}

int aleatorio(int i,int j){
    int ran = (rand() % 2); // se rand for par da 0, se for impar da 1
    if (ran > 0) return i;
    else return j;
}
