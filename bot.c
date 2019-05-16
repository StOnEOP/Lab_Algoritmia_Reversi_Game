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


void bot(ESTADO e, char peca,int nivel){
    VALOR pecaBot = charToValor(peca);
    while (isOver(e) != 1){                //enquanto nao se chegar ao fim do jogo, ie, já nao ha mais jogadas
        while (validasJogada(e) != 0) {   //enquanto houver jogadas validas para a peça atual
            if e.peca
        }
    }

}