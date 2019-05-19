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


/*ESTADO bot(ESTADO e, char peca,){    //gamestate, peca do bot, nivel do bot
    VALOR pecaBot = charToValor(peca);
    while (isOver(e) != 1) {                //enquanto nao se chegar ao fim do jogo, ie, já nao ha mais jogadas
        while (validasJogada(e) != 0) {     //enquanto houver jogadas validas para a peça atual
            if (e.peca == pecaBot) {
                e = jogaBot(e);
                return e;
            } else {
                e = jogaPlayer(e);
                return e;
            }
        }
    }

}

ESTADO jogaBot (ESTADO e){
    int bLinha=0;int bColuna=0;         //coordenadas para depois receber a jogada do bot
    selectJogada(e,bLinha,bColuna);
    e=jogar(e,bLinha,bColuna);
    e.peca = inverte(e.peca);
    return e;
}

void selectJogada (ESTADO e, int* bLinha, int* bColuna){     // envia 1 estado, 1 nivel e 2 variaveis, para depois receber coordenadas nessas variaveis
    /*
     * TODO:
     * procurar de todas as VALIDAS, a que tem melhor score. logo temos de adicionar o score as validas
     */
    /*switch(e.nivel){
        case 0:
    }


}*/