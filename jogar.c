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



ESTADO jogar(ESTADO e,int linha,int coluna) {
    //if (isOver == 1) printf("Jogo Terminado\n"); // se jã nao houver jogadas possiveis
    else if(jogadaValida(e,linha,coluna)) {
            e.grelha[linha][coluna] = e.peca;
            e=virapecas(e,linha,coluna);
            addHjogada(e.peca,linha,coluna);
         } else printf("Jogada Invalida\n");
        e.peca=inverte(e.peca);
        return e;


}

int jogadaValida(ESTADO e, int linha,int coluna){
    if(linha>=0 && linha <8 && coluna >=0 && coluna < 8 && e.grelha[linha][coluna]==VAZIA && check(e,linha,coluna)){
        return 1;
    }else return 0;
}

int check(ESTADO e,int linha,int coluna){
    int r=0;
    r = checkLinhadir(e, linha, coluna) + checkLinhaesq(e,linha,coluna) + checkColunabaixo(e, linha, coluna) +
            checkColunacima(e,linha, coluna) + checkDiagDirbaixo(e, linha, coluna) + checkDiagDirCima(e, linha,coluna)
            +checkDiagEsqbaixo(e,linha,coluna) + checkDiagEsqcima(e,linha,coluna);
    return r;
}

int checkLinhadir(ESTADO e,int linha,int coluna) {
    int c;
    if (e.grelha[linha][coluna + 1] == inverte(e.peca)) {
        for(c=coluna+2;c<8;c++){
            if(e.grelha[linha][c]==e.peca){
                return 1;
            }


        }

    }
    return 0;
}

int checkLinhaesq(ESTADO e,int linha,int coluna){
    int c;
    if(e.grelha[linha][coluna-1]== inverte(e.peca)){
        for(c=coluna-2;c>=0;c--){
            if(e.grelha[linha][c]){
                return 1;
            }
        }
    }
    return 0;

}

int checkColunabaixo(ESTADO e,int linha, int coluna) {
    int l;
    if (e.grelha[linha + 1][coluna] == inverte(e.peca)) {
        for (l = linha - 2; l < 8; l++) {
            if (e.grelha[l][coluna] == e.peca) {
                return 1;
            }
        }
        return 0;
    }
}

int checkColunacima(ESTADO e,int linha, int coluna){
        int l;
        if(e.grelha[linha-1][coluna]== inverte(e.peca)) {
            for(l=linha-2;l>=0;l--) {
                if(e.grelha[l][coluna]==e.peca){
                    return 1;
                }
            }
        }
    return 0;
}


int checkDiagDirbaixo(ESTADO e,int linha, int coluna) {
    int l,c;

    if (e.grelha[linha + 1][coluna + 1] == inverte(e.peca)) {
        for(l=linha+2,c=coluna+2;l<8, c<8;l++,c++){
            if(e.grelha[l][c]==e.peca){
                return 1;
            }
        }
    }
    return 0;
}

int checkDiagDirCima(ESTADO e,int linha, int coluna) {
    int c,l;
    if (e.grelha[linha -1][coluna +1] == inverte(e.peca)) {
        for(l=linha-2,c=coluna+2;l>=0,c<8;l--,c++) {
            if(e.grelha[l][c]==e.peca){
                return 1;
            }
        }
        return 0;
    }
}

int checkDiagEsqbaixo(ESTADO e,int linha, int coluna) {
    int l,c;
    if (e.grelha[linha + 1][coluna - 1] == inverte(e.peca)) {
        for(l=linha+2,c=coluna-2;l < 8,c>=0;l++,c--) {
            if(e.grelha[l][c]){
                return 1;
            }
        }
    }
    return 0;
}

int checkDiagEsqcima(ESTADO e,int linha, int coluna) {
    int l,c;
    if (e.grelha[linha - 1][coluna - 1] == inverte(e.peca)) {
        for(l=linha-2,c=coluna-2;l--,c--;l>=0,c>=0){
            if(e.grelha[l][c]==e.peca){
                return 1;
            }
        }
    }
    return 0;
}

ESTADO virapecas(ESTADO e,int linha , int coluna){
    int l ,c ;
    if (checkLinhadir(e,linha,coluna)){//fazer para os outros checks
        for(c=coluna+1;e.grelha[linha][c]!=e.peca;c++){
            if(e.grelha[linha][c]==inverte(e.peca)){
                e.grelha[linha][c]=e.peca;
            }
        }
    }
    if(checkLinhaesq(e,linha,coluna)){
        for(c=coluna-1;e.grelha[linha][c]!=e.peca;c--){
            if(e.grelha[linha][c]==inverte(e.peca)) {
                e.grelha[linha][c] = e.peca;
            }
        }
    }
    if(checkColunacima(e,linha,coluna)){
        for(l=linha-1;e.grelha[l][coluna]!=e.peca;l--){
            if(e.grelha[l][coluna]==inverte(e.peca)){
                e.grelha[l][coluna]= e.peca;
            }
        }
    }
    if(checkColunabaixo(e,linha,coluna)){
        for(l=linha+1;e.grelha[l][coluna]!=e.peca;l++) {
            if (e.grelha[l][coluna] == inverte(e.peca)) {
                e.grelha[l][coluna] = e.peca;
            }
        }
    }
    if(checkDiagDirCima(e,linha,coluna)){
        for(l=linha-1,c=coluna+1;e.grelha[l][c]!=e.peca;l--,c++){
            if(e.grelha[l][c]==inverte(e.peca)){
                e.grelha[l][c]=e.peca;
            }
        }
    }
    if(checkDiagDirbaixo(e,linha,coluna)){
        for(l=linha+1,c=coluna+1;e.grelha[l][c]!=e.peca;l++,c++){
            if(e.grelha[l][c]==inverte(e.peca)){
                e.grelha[l][c]=e.peca;
            }
        }
    }
    if(checkDiagEsqcima(e,linha,coluna)){
        for(l=linha-1,c=coluna-1;e.grelha[l][c]!=e.peca;l--,c--){
            if(e.grelha[l][c]==inverte(e.peca)){
                e.grelha[l][c]=e.peca;
            }
        }

    }
    if(checkDiagEsqbaixo(e,linha,coluna)){
        for(l=linha+1,c=coluna-1;e.grelha[l][c]!=e.peca;l++,c--){
            if(e.grelha[l][c]==inverte(e.peca)){
                e.grelha[l][c]=e.peca;
            }
        }
    }
    return e;
}


