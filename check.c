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
    r =   checkLinhadir    (e, linha, coluna,p)   + checkLinhaesq(e,linha,coluna,p)
        + checkColunabaixo (e, linha, coluna,p)  + checkColunacima(e,linha, coluna,p)
        + checkDiagDirbaixo(e, linha, coluna,p) + checkDiagDirCima(e, linha,coluna,p)
        + checkDiagEsqbaixo(e, linha, coluna,p)   + checkDiagEsqcima(e,linha,coluna,p);

    return r;
}

int checkLinhadir(ESTADO e,int linha,int coluna, VALOR p) {
    int c; int sc=0;
    if (e.grelha[linha][coluna + 1] == p) {
        for(c=coluna+2;c<8;c++){
            sc++;
            if(e.grelha[linha][c]==e.peca){
                return sc;
            }
        }
    }
    return 0;
}

int checkLinhaesq(ESTADO e,int linha,int coluna,VALOR p){
    int c;int sc=0;
    if(e.grelha[linha][coluna-1]== p){
        for(c=coluna-2;c>=0;c--){
            sc++;
            if(e.grelha[linha][c]){
                return sc;
            }
        }
    }
    return 0;
}

int checkColunabaixo(ESTADO e,int linha, int coluna,VALOR p) {
    int l;int sc=0;
    if (e.grelha[linha + 1][coluna] == p) {
        for (l = linha + 2; l < 8; l++) {
            sc++;
            if (e.grelha[l][coluna] == e.peca) {
                return sc;
            }
        }
    }
    return 0;
}

int checkColunacima(ESTADO e,int linha, int coluna,VALOR p){
    int l;int sc=0;
    if(e.grelha[linha-1][coluna]== p) {
        for(l=linha-2;l>=0;l--) {
            sc++;
            if(e.grelha[l][coluna]==e.peca){
                return sc;
            }
        }
    }
    return 0;
}


int checkDiagDirbaixo(ESTADO e,int linha, int coluna,VALOR p) {
    int l,c;int sc=0;
    if (e.grelha[linha + 1][coluna + 1] == p) {
        for(l=linha+2,c=coluna+2; l<8 && c<8;l++,c++){
            sc++;
            if(e.grelha[l][c]==e.peca){
                return sc;
            }
        }
    }
    return 0;
}

int checkDiagDirCima(ESTADO e,int linha, int coluna,VALOR p) {
    int c,l;int sc=0;
    if (e.grelha[linha -1][coluna +1] == p) {
        for(l=linha-2,c=coluna+2; l>=0  && c<8;l--,c++) {
            sc++;
            if(e.grelha[l][c]==e.peca){
                return sc;
            }

        }
    }
    return 0;
}


int checkDiagEsqbaixo(ESTADO e,int linha, int coluna,VALOR p) {
    int l,c;int sc=0;
    if (e.grelha[linha + 1][coluna - 1] == p) {
        for(l=linha+2,c=coluna-2;l < 8 && c>=0;l++,c--) {
            sc++;
            if(e.grelha[l][c]==e.peca){
                return sc;
            }
        }
    }
    return 0;
}
int checkDiagEsqcima(ESTADO e,int linha, int coluna,VALOR p) {
    int l,c;int sc=0;
    if (e.grelha[linha - 1][coluna - 1] == p) {
        for(l=linha-2,c=coluna-2;l>=0 && c>=0;l--,c--){
            sc++;
            if(e.grelha[l][c]==e.peca){
                return sc;
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
/*ESTADO virapecasinverças(ESTADO e,int linha , int coluna){
    int l ,c ;
    VALOR p = inverte(e.peca);
    if (checkLinhadir(e,linha,coluna,e.peca)){//fazer para os outros checks
        for(c=coluna+1;e.grelha[linha][c]!=p;c++){
            if(e.grelha[linha][c]==p){
                e.grelha[linha][c]=p;
            }
        }
    }
    if(checkLinhaesq(e,linha,coluna,e.peca)){
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
}*/