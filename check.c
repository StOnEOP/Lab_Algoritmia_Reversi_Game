//
// Created by andre on 15/05/2019.
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
    int r=0;VALOR p;
    p = inverte(e.peca);
    r = checkLinhadir(e, linha, coluna,p) + checkLinhaesq(e,linha,coluna,p)
        + checkColunabaixo(e, linha, coluna,p) + checkColunacima(e,linha, coluna,p)
        + checkDiagDirbaixo(e, linha, coluna,p) + checkDiagDirCima(e, linha,coluna,p)
        +checkDiagEsqbaixo(e,linha,coluna,p) + checkDiagEsqcima(e,linha,coluna,p);

    return r;
}

int checkLinhadir(ESTADO e,int linha,int coluna, VALOR p) {
    int c;
    if (e.grelha[linha][coluna + 1] == p) {
        for(c=coluna+2;c<8;c++){
            if(e.grelha[linha][c]==e.peca){
                return 1;
            }
        }
    }
    return 0;
}

int checkLinhaesq(ESTADO e,int linha,int coluna,VALOR p){
    int c;
    if(e.grelha[linha][coluna-1]== p){
        for(c=coluna-2;c>=0;c--){
            if(e.grelha[linha][c]){
                return 1;
            }
        }
    }
    return 0;
}

int checkColunabaixo(ESTADO e,int linha, int coluna,VALOR p) {
    int l;
    if (e.grelha[linha + 1][coluna] == p) {
        for (l = linha - 2; l < 8; l++) {
            if (e.grelha[l][coluna] == e.peca) {
                return 1;
            }
        }
        return 0;
    }
}

int checkColunacima(ESTADO e,int linha, int coluna,VALOR p){
    int l;
    if(e.grelha[linha-1][coluna]== p) {
        for(l=linha-2;l>=0;l--) {
            if(e.grelha[l][coluna]==e.peca){
                return 1;
            }
        }
    }
    return 0;
}


int checkDiagDirbaixo(ESTADO e,int linha, int coluna,VALOR p) {
    int l,c;
    if (e.grelha[linha + 1][coluna + 1] == p) {
        for(l=linha+2,c=coluna+2;l<8, c<8;l++,c++){
            if(e.grelha[l][c]==e.peca){
                return 1;
            }
        }
    }
    return 0;
}

int checkDiagDirCima(ESTADO e,int linha, int coluna,VALOR p) {
    int c,l;
    if (e.grelha[linha -1][coluna +1] == p) {
        for(l=linha-2,c=coluna+2;l>=0,c<8;l--,c++) {
            if(e.grelha[l][c]==e.peca){
                return 1;
            }

        }
        return 0;


    }
}


int checkDiagEsqbaixo(ESTADO e,int linha, int coluna,VALOR p) {
    int l,c;
    if (e.grelha[linha + 1][coluna - 1] == p) {
        for(l=linha+2,c=coluna-2;l < 8,c>=0;l++,c--) {
            if(e.grelha[l][c]==e.peca){
                return 1;
            }
        }
    }
    return 0;
}
int checkDiagEsqcima(ESTADO e,int linha, int coluna,VALOR p) {
    int l,c;
    if (e.grelha[linha - 1][coluna - 1] == p) {
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
    VALOR p = inverte(e.peca);
    if (checkLinhadir(e,linha,coluna,p)){//fazer para os outros checks
        for(c=coluna+1;e.grelha[linha][c]!=e.peca;c++){
            if(e.grelha[linha][c]==p){
                e.grelha[linha][c]=e.peca;
            }
        }
    }
    if(checkLinhaesq(e,linha,coluna,p)){
        for(c=coluna-1;e.grelha[linha][c]!=e.peca;c--){
            if(e.grelha[linha][c]==p) {
                e.grelha[linha][c] = e.peca;
            }
        }
    }
    if(checkColunacima(e,linha,coluna,p)){
        for(l=linha-1;e.grelha[l][coluna]!=e.peca;l--){
            if(e.grelha[l][coluna]==p){
                e.grelha[l][coluna]= e.peca;
            }
        }
    }
    if(checkColunabaixo(e,linha,coluna,p)){
        for(l=linha+1;e.grelha[l][coluna]!=e.peca;l++) {
            if (e.grelha[l][coluna] == p) {
                e.grelha[l][coluna] = e.peca;
            }
        }
    }
    if(checkDiagDirCima(e,linha,coluna,p)){
        for(l=linha-1,c=coluna+1;e.grelha[l][c]!=e.peca;l--,c++){
            if(e.grelha[l][c]==p){
                e.grelha[l][c]=e.peca;
            }
        }
    }
    if(checkDiagDirbaixo(e,linha,coluna,p)){
        for(l=linha+1,c=coluna+1;e.grelha[l][c]!=e.peca;l++,c++){
            if(e.grelha[l][c]==p){
                e.grelha[l][c]=e.peca;
            }
        }
    }
    if(checkDiagEsqcima(e,linha,coluna,p)){
        for(l=linha-1,c=coluna-1;e.grelha[l][c]!=e.peca;l--,c--){
            if(e.grelha[l][c]==p){
                e.grelha[l][c]=e.peca;
            }
        }

    }
    if(checkDiagEsqbaixo(e,linha,coluna,p)){
        for(l=linha+1,c=coluna-1;e.grelha[l][c]!=e.peca;l++,c--){
            if(e.grelha[l][c]==p){
                e.grelha[l][c]=e.peca;
            }
        }
    }
    return e;
}

int isover(ESTADO e){
    int i,j;
    int r=0;
    int p=1;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(e.grelha[i][j]==VALIDA){
                r=1;
            }else if(e.grelha[i][j]!= VAZIA){
                p=1;
            }
        }
    }
    if(r){
        e.peca=inverte(e.peca);
    }
}