//
// Created by Pedro Faria - A72640 02/05/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estado.h"
#include "interpretador.h"
#include "faria.h"
#include "jogar.h"

void limpavalidas(ESTADO *e){
    for(int i=0;i<8;i++) {
        for (int j = 0; j < 8; j++) {
            if(e->grelha[i][j]==VALIDA){
                e->grelha[i][j]=VAZIA;
            }
        }
    }

}

void jogar(ESTADO *e,int linha,int coluna){ // verifica se a jogada é valida e joga-a
    // verificar se a jogada é valida e se o local selecionado está vazio
    if ((jogadaValida(e,linha,coluna) == 0) || e->grelha[linha-1][coluna-1] ==VALOR_X||e->grelha[linha-1][coluna-1]==VALOR_O) {
        printf("Jogada Invalida\n");
    }else if(e->grelha[linha-1][coluna-1]==VALIDA){
        e->grelha[linha-1][coluna-1] = e->peca;
        //virarpeças
    }
    limpavalidas(e);

}

int jogadaValida(ESTADO *e, int linha, int coluna){
    int r=0;
    for(int i=0;i<8;i++) {
        for (int j = 0; j < 8; j++) {

            checkLinha(&e, i, j);
            checkColuna(&e, i, j);
            checkDiagEsq(&e, i, j);
            checkDiagDir(&e, i, j);
        }
    }
    if(e->grelha[linha-1][coluna-1]==VALIDA){
        r=1;
    }
    return r;
}
/*VALOR oposto(VALOR v){
    if(v==VALOR_X){
        return VALOR_O;
    }else if(v==VALOR_O){
        return VALOR_X;
    }
}*/

int checkLinha(ESTADO *e,int linha,int coluna){
    int p = 0; int l=linha; int c =coluna; int c2=coluna-2;
    if(e->grelha[linha-1][coluna]== inverte(*e)){
        while(e->grelha[linha-1][c]==inverte(*e) || coluna < 8 ){
            ++c;
            p=1;

            if(p){
                e->grelha[linha][coluna]=VALIDA;


        }

        }

    }else if(e->grelha[linha-1][coluna-2]== inverte(*e)){
        while(e->grelha[linha-1][c2]==inverte(*e) || coluna > 0 ){
            --c2;
            p=1;

            if(p){
                e->grelha[linha][coluna]=VALIDA;


             }

        }

    }

}

int checkColuna(ESTADO *e,int linha, int coluna) {
    int p = 0; int l=linha; int c =coluna; int l2 =linha-2;
    if(e->grelha[linha-1][coluna]== inverte(*e)){
        while(e->grelha[l][coluna-1]==inverte(*e)||linha < 8 || coluna < 8 ){
            ++l;
            p=1;
            if(p){
                e->grelha[linha][coluna]=VALIDA;
            }


        }


    }else if(e->grelha[linha-2][coluna-1]== inverte(*e)){
        while(e->grelha[l2][coluna-1]!=e->peca||linha >0|| coluna > 0 ){
            --l2;
            p=1;
            if(p){
                e->grelha[linha][coluna]=VALIDA;
            }


        }


    }

}


int checkDiagDir(ESTADO *e,int linha, int coluna){ // verifica se há uma jogada valida na Diagonal direita
    int c = coluna;int l = linha; int reg = 0; int i = 0;
    VALOR inverso; // vamos crirar 1 variavel com o inverso da nossa peca de jogo de forma a confirmar que a jogada é valida
    if(e.peca == VALOR_X) inverso = VALOR_O;
    else inverso = VALOR_X;
    // Vamos procurar se a linha é valida apartir da posiçao dada, logo iremos correr a mesma 2 vezes
    while ((c > 0) || (l>0)){
        l--; c--;
        if (e.grelha[l][c] == VAZIA ) break; // se encontrar 1 local vazio antes de 1 inverso e 1 peça nao é valido logo salta fora
        if (e.grelha[l][c] == inverso) i = 1;
        if (e.grelha[l][c] == e.peca) reg = 1;
        if (reg ==1 && i==1) return 1; // fucionará?
    }
    c = coluna; l = linha;  reg = i = 0;
    while ((c < 7) || (l <7)){
        l++; c++;
        if (e.grelha[l][c] == VAZIA ) break; // se encontrar 1 local vazio antes de 1 inverso e 1 peça nao é valido logo salta fora
        if (e.grelha[l][c] == inverso) i = 1;
        if (e.grelha[l][c] == e.peca) reg = 1;
        if (reg ==1 && i==1) return 1; // fucionará?
    }
    return 0;
}

int checkDiagEsq(ESTADO *e,int linha, int coluna) { // verifica se há uma jogada valida na Diagonal direita
    int c = coluna;
    int l = linha;
    int reg = 0;
    int i = 0;
    VALOR inverso; // vamos crirar 1 variavel com o inverso da nossa peca de jogo de forma a confirmar que a jogada é valida
    if (e.peca == VALOR_X) inverso = VALOR_O;
    else inverso = VALOR_X;
    // Vamos procurar se a linha é valida apartir da posiçao dada, logo iremos correr a mesma 2 vezes
    while ((c < 7) || (l > 0)) {
        l--;
        c++;
        if (e.grelha[l][c] == VAZIA)
            break; // se encontrar 1 local vazio antes de 1 inverso e 1 peça nao é valido logo salta fora
        if (e.grelha[l][c] == inverso) i = 1;
        if (e.grelha[l][c] == e.peca) reg = 1;
        if (reg == 1 && i == 1) return 1; // fucionará?
    }
    c = coluna;
    l = linha;
    reg = i = 0;
    while ((c > 0) || (l < 7)) {
        l++;
        c--;
        if (e.grelha[l][c] == VAZIA)
            break; // se encontrar 1 local vazio antes de 1 inverso e 1 peça nao é valido logo salta fora
        if (e.grelha[l][c] == inverso) i = 1;
        if (e.grelha[l][c] == e.peca) reg = 1;
        if (reg == 1 && i == 1) return 1; // fucionará?
    }
    return 0;


}//void virarPecas(ESTADO e,int linha,int coluna){}
