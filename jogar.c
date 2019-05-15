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
    /*else*/ if(jogadaValida(e,linha,coluna)) {
            e.grelha[linha][coluna] = e.peca;
            e=virapecas(e,linha,coluna);
            addHjogada(e.peca,linha,coluna);
            e.peca=inverte(e);
         } else printf("Jogada Invalida\n");

        return e;


}

int jogadaValida(ESTADO e, int linha,int coluna){
    if(linha>=0 && linha <8 && coluna >=0 && coluna < 8 && e.grelha[linha][coluna]==VAZIA && check(e,linha,coluna) != 0){
        return 1;
    }else return 0;
}


ESTADO virapecas(ESTADO e,int linha , int coluna){
    int l ,c ;
    if (checkLinhadir(e,linha,coluna)){//fazer para os outros checks
        for(c=coluna+1;e.grelha[linha][c]!=e.peca;c++){
            if(e.grelha[linha][c]==inverte(e)){
                e.grelha[linha][c]=e.peca;
            }
        }
    }
    if(checkLinhaesq(e,linha,coluna)){
        for(c=coluna-1;e.grelha[linha][c]!=e.peca;c--){
            if(e.grelha[linha][c]==inverte(e)) {
                e.grelha[linha][c] = e.peca;
            }
        }
    }
    if(checkColunacima(e,linha,coluna)){
        for(l=linha-1;e.grelha[l][coluna]!=e.peca;l--){
            if(e.grelha[l][coluna]==inverte(e)){
                e.grelha[l][coluna]= e.peca;
            }
        }
    }
    if(checkColunabaixo(e,linha,coluna)){
        for(l=linha+1;e.grelha[l][coluna]!=e.peca;l++) {
            if (e.grelha[l][coluna] == inverte(e)) {
                e.grelha[l][coluna] = e.peca;
            }
        }
    }
    if(checkDiagDirCima(e,linha,coluna)){
        for(l=linha-1,c=coluna+1;e.grelha[l][c]!=e.peca;l--,c++){
            if(e.grelha[l][c]==inverte(e)){
                e.grelha[l][c]=e.peca;
            }
        }
    }
    if(checkDiagDirbaixo(e,linha,coluna)){
        for(l=linha+1,c=coluna+1;e.grelha[l][c]!=e.peca;l++,c++){
            if(e.grelha[l][c]==inverte(e)){
                e.grelha[l][c]=e.peca;
            }
        }
    }
    if(checkDiagEsqcima(e,linha,coluna)){
        for(l=linha-1,c=coluna-1;e.grelha[l][c]!=e.peca;l--,c--){
            if(e.grelha[l][c]==inverte(e)){
                e.grelha[l][c]=e.peca;
            }
        }

    }
    if(checkDiagEsqbaixo(e,linha,coluna)){
        for(l=linha+1,c=coluna-1;e.grelha[l][c]!=e.peca;l++,c--){
            if(e.grelha[l][c]==inverte(e)){
                e.grelha[l][c]=e.peca;
            }
        }
    }
    return e;
}


