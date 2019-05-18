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
//
#include "undo.h"

void undoJogada(ESTADO e){
    int linha,coluna;
    int i=2;
// recebe a posiçao da ultima jogada, do topo da stack atençao que terá sempre de se fazer
    while(i>0){ // temos sempre de tirar 1 jogada caso o modo seja M e 2 caso seja A, pois as jogadas do oponente contam
        linha = top->linha;
        coluna = top->coluna;
        //desvirarPecas(e,linha, coluna);
        rmUltimaJogada();
        i--;
    }
}

/*void desvirarPecas(ESTADO e,int linha, int coluna){
    VALOR pos =e.grelha[linha][coluna];
    undoH(pos,linha,coluna);
    undoV(pos,linha,coluna);
    undoDdir(pos,linha,coluna); // \ -> Diagonal direita
    undoDesq(pos,linha,coluna); // / -> Diagonal esquerda

}*/