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

int peso[8][8] = {99,-8,8,6,6,8,-8,99,-8,-24,-4,-3,-3,-4,-24,-8,8,-4,7,4,4,7,-4,8,6,-3,4,0,0,4,-3,6,6,-3,4,0,0,4,-3,6,8,-4,7,4,4,7,-4,8,-8,-24,-4,-3,-3,-4,-24,-8,99,-8,8,6,6,8,-8,99} ; // cria a tabela de pesos

ESTADO bot(ESTADO e, char peca){    //gamestate, peca do player, nivel do bot
    VALOR pecaBot = charToValor(peca);
    VALOR pecaPc = inverte(pecaBot);
    e.peca= VALOR_X;
    while (isOver(e) != 1) {                //enquanto nao se chegar ao fim do jogo, ie, já nao ha mais jogadas
        while (validasJogada(e) != 0) {     //enquanto houver jogadas validas para a peça atual
            if (e.peca == pecaBot) {
                e = jogaBot(e);

            } else {
                e = jogaPlayer(e);

            }
        }
    }

}

ESTADO jogaBot (ESTADO e){
    int* bLinha; int* bColuna;         //coordenadas para depois receber a jogada do bot
    selectJogada(e,*bLinha,*bColuna);
    e=jogar(e,bLinha,bColuna);
    e.peca = inverte(e.peca);
    return e;
}

int selectJogada (ESTADO e, int bLinha, int bColuna){     // envia 1 estado, 1 nivel e 2 variaveis, para depois receber coordenadas nessas variaveis
    /*
     * TODO:
     * procurar de todas as VALIDAS, a que tem melhor score. logo temos de adicionar o score as validas
     */
    int tmp=0;int res=0;
    for (int i = 0; i <8 ; ++i) {
        for (int j = 0; j < ; ++j) {
            if (check(e,i,j)!=0){ // caso a jogada seja valida
                tmp = checkScore(e,i,j); //guarda o score da mesma numa variavel
                if (tmp == res){
                    res = aleatorio(tmp,res); //seleciona 1 de forma aleatoria
                }else if (tmp>res) {
                    res=tmp;
                    bLinha=i;
                    bColuna=j;
                }


            }

        }
    }

return 0;
}

int checkScore(ESTADO e,int l,int j){ //recebe 1 coordenada e devolve o score da mesma usando minmax

}

int aleatorio(int i,int j){
    int ran = rand() % 2; // se rand for par da 0, se for impar da 1
    if (ran > 0) return i;
    else return j;
}