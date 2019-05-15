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

ESTADO validasJogada(ESTADO e) { // recebe 1 estado e devolve um estado com jogadas validas
    // corre a funçao á procura de peças
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++){
            if(e.grelha[i][j]==inverte(e)){ // procura peças inversa a nossa, ie locais onde sera possivel jogar
                e=checkVal(e,i,j); // dado 1 estado, e coordenadas, poe todas as jogadas validas como sendo VALIDA
            }
        }
    }
  return e;
}
ESTADO retiraValida(ESTADO e){ // recebe 1 estado, e devolve esse estado com vazia onde antes tinha valida
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++){
        if(e.grelha[i][j]==VALIDA) e.grelha[i][j] = VAZIA;
        }
    }
    return e;
}
ESTADO checkVal(ESTADO e,int linha,int coluna){
    checkVLinhadir(e, linha, coluna); checkVLinhaesq(e,linha,coluna);checkVColunabaixo(e, linha, coluna);
    checkVColunacima(e,linha, coluna);checkVDiagDirbaixo(e, linha, coluna);checkVDiagDirCima(e, linha,coluna);
    checkVDiagEsqbaixo(e,linha,coluna);checkVDiagEsqcima(e,linha,coluna);
    return e;
}

void checkVLinhaesq(ESTADO e,int linha,int coluna){ // verifica a linha á esquerda e devolve a pontuaçao da jogada
    int c;
    if (e.grelha[linha][coluna+1] == VAZIA){ // como procura a esquerda, á direita tera de ter Vazia
        for(c=coluna-1;c>=0;c--){
            if (e.grelha[linha][c]==e.peca) {
                e.grelha[linha][coluna + 1] = VALIDA; //caso encontre torna a Vazia em Valida
            }
        }
    }
}

void checkVLinhadir(ESTADO e,int linha,int coluna){ // verifica a linha á esquerda e devolve a pontuaçao da jogada
    int c;
    if (e.grelha[linha][coluna-1] == VAZIA){ // como procura a direita, á esquerda tera de ter Vazia
        for(c=coluna+1;c>=0;c++){
            if (e.grelha[linha][c]==e.peca) {
                e.grelha[linha][coluna - 1] = VALIDA; //caso encontre torna a Vazia em Valida
            }
        }
    }
}

void checkVColunabaixo(ESTADO e,int linha,int coluna){ // verifica a coluna para baixo e devolve a pontuaçao da jogada
    int l;
    if (e.grelha[linha-1][coluna] == VAZIA){ // como procura para baixo, a cima tera de ter Vazia
        for(l=linha+1;l<8;l++){
            if (e.grelha[linha][l]==e.peca) {
                e.grelha[linha][coluna + 1] = VALIDA; //caso encontre torna a Vazia em Valida
            }
        }
    }
}

void checkVColunacima(ESTADO e,int linha,int coluna){ // verifica a coluna para cima e devolve a pontuaçao da jogada
    int l;
    if (e.grelha[linha+1][coluna] == VAZIA){    // como procura para cima, a baixo tera de ter Vazia
        for(l=linha-1;l>=0;l--){            // procura apartir da peça
            if (e.grelha[linha][l]==e.peca) {
                e.grelha[linha][coluna + 1] = VALIDA; //caso encontre torna a Vazia em Valida
            }
        }
    }
}

void checkVDiagDirbaixo(ESTADO e,int linha, int coluna) {
    int l,c;
    if (e.grelha[linha - 1][coluna -1] == VAZIA) {
        for(l=linha+2,c=coluna+2;l<8, c<8;l++,c++){
            if(e.grelha[l][c]==e.peca){
               e.grelha[linha-1][coluna-1] = VALIDA;
            }
        }
    }
}

void checkVDiagDirCima(ESTADO e,int linha, int coluna) {
    int c,l;
    if (e.grelha[linha +1][coluna -1] == VAZIA) {
        for(l=linha-2,c=coluna+2;l>=0,c<8;l--,c++) {
            if(e.grelha[l][c]==e.peca){
                e.grelha[linha +1][coluna -1] = VALIDA;
            }
        }
    }
}

void checkVDiagEsqbaixo(ESTADO e,int linha, int coluna) {
    int l,c;
    if (e.grelha[linha - 1][coluna + 1] == VAZIA) {
        for(l=linha+2,c=coluna-2;l < 8,c>=0;l++,c--) {
            if(e.grelha[l][c]){
                e.grelha[linha - 1][coluna + 1] = VALIDA;
            }
        }
    }
}

void checkVDiagEsqcima(ESTADO e,int linha, int coluna) {
    int l,c;
    if (e.grelha[linha + 1][coluna + 1] == VAZIA) {
        for(l=linha-2,c=coluna-2;l--,c--;l>=0,c>=0){
            if(e.grelha[l][c]==e.peca){
                e.grelha[linha + 1][coluna + 1] = VALIDA;
            }
        }
    }
}