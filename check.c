//
// Created by pedro on 15/05/2019.
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


int check(ESTADO e,int linha,int coluna){
    int r=0;
    r = checkLinhadir(e, linha, coluna) + checkLinhaesq(e,linha,coluna) + checkColunabaixo(e, linha, coluna) +
        checkColunacima(e,linha, coluna) + checkDiagDirbaixo(e, linha, coluna) + checkDiagDirCima(e, linha,coluna)
        +checkDiagEsqbaixo(e,linha,coluna) + checkDiagEsqcima(e,linha,coluna);
    return r;
}

int checkLinhadir(ESTADO e,int linha,int coluna) {
    int c;
    if (e.grelha[linha][coluna + 1] == inverte(e)) {
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
    if(e.grelha[linha][coluna-1]== inverte(e)){
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
    if (e.grelha[linha + 1][coluna] == inverte(e)) {
        for (l = linha + 2; l < 8; l++) {
            if (e.grelha[l][coluna] == e.peca) {
                return 1;
            }
        }
        return 0;
    }
}

int checkColunacima(ESTADO e,int linha, int coluna){
    int l;
    if(e.grelha[linha-1][coluna]== inverte(e)) {
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

    if (e.grelha[linha + 1][coluna + 1] == inverte(e)) {
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
    if (e.grelha[linha -1][coluna +1] == inverte(e)) {
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
    if (e.grelha[linha + 1][coluna - 1] == inverte(e)) {
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
    if (e.grelha[linha - 1][coluna - 1] == inverte(e)) {
        for(l=linha-2,c=coluna-2;l>=0,c>=0;l--,c--){
            if(e.grelha[l][c]==e.peca){
                return 1;
            }
        }
    }
    return 0;
}