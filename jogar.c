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
#include "faria.h"
#include "jogar.h"

void jogar(ESTADO *e,int l,int c){ // verifica se a jogada é valida e joga-a
    int linha  = l-1;
    int coluna = c-1;
    int reg = 0;
    // verificar se a jogada é valida e se o local selecionado está vazio
    if ((jogadaValida(*e,linha,coluna) == 0) || e->grelha[linha][coluna] != VAZIA) printf("Jogada Invalida\n");

    else {
        printf("\nbreak1\n"); // TESTE
        e->grelha[linha][coluna] = e->peca;   // poe 1 peça no local
        //virarPecas(e,linha,coluna);
    }

}

int jogadaValida(ESTADO e, int linha, int coluna){ // 1 == verdade 0== falso
    if (linha >7 || linha < 0 || coluna >7 || coluna <0) return 0; // se o local for fora do tabuleiro a jogada não é valida
        // verifica se há outra peça igual a da jogada horizontalmente, verticalmente e em ambas as diagonais, caso 1 delas exista a jogada é valida, logo retorna True
    else if ((checkLinha(e,linha,coluna) == 1) || (checkColuna(e,linha,coluna) == 1)
            || (checkDiagDir(e,linha,coluna) == 1) || (checkDiagEsq(e,linha,coluna) == 1)) {printf("valida é verdade\n");return 1;} //TESTE
         else {printf("NAO E VALIDA \n");return 0;}// caso nenhuma das funçoes anteriores dê verdade, significa que a nao há jogadas validas
}

int checkLinha(ESTADO e,int linha,int coluna){ // 1 == True, 0== False
    int l = linha; int reg = 0; int i = 0;
    VALOR inverso; // vamos crirar 1 variavel com o inverso da nossa peca de jogo de forma a confirmar que a jogada é valida
    if(e.peca == VALOR_X) inverso = VALOR_O;
    else inverso = VALOR_X;
    // Vamos procurar se a linha é valida apartir da posiçao dada, logo iremos correr a mesma 2 vezes
    while (l > 0){
        l--;
        if (e.grelha[l][coluna] == VAZIA ) break; // se encontrar 1 local vazio antes de 1 inverso e 1 peça nao é valido logo salta fora
        if (e.grelha[l][coluna] == inverso) i = 1;
        if (e.grelha[l][coluna] == e.peca) reg = 1;
        if (reg ==1 && i==1) return 1; // fucionará?
    }
    l = linha; reg = i = 0;
    while (l < 7){
        l++;
        if (e.grelha[l][coluna] == VAZIA ) break; // se encontrar 1 local vazio antes de 1 inverso e 1 peça nao é valido logo salta fora
        if (e.grelha[l][coluna] == inverso) i = 1;
        if (e.grelha[l][coluna] == e.peca) reg = 1;
        if (reg ==1 && i==1) return 1; // fucionará?
    }
    return 0;
}

int checkColuna(ESTADO e,int linha, int coluna){ // verifica se há uma jogada valida na coluna
    int c = coluna; int reg = 0; int i = 0;
    VALOR inverso; // vamos crirar 1 variavel com o inverso da nossa peca de jogo de forma a confirmar que a jogada é valida
    if(e.peca == VALOR_X) inverso = VALOR_O;
    else inverso = VALOR_X;
    // Vamos procurar se a linha é valida apartir da posiçao dada, logo iremos correr a mesma 2 vezes
    while (c > 0){
        c--;
        if (e.grelha[linha][c] == VAZIA ) break; // se encontrar 1 local vazio antes de 1 inverso e 1 peça nao é valido logo salta fora
        if (e.grelha[linha][c] == inverso) i = 1;
        if (e.grelha[linha][c] == e.peca) reg = 1;
        if (reg ==1 && i==1) return 1; // fucionará?
    }
    c = coluna; reg = i = 0;
    while (c < 7){
        c++;
        if (e.grelha[linha][c] == VAZIA ) break; // se encontrar 1 local vazio antes de 1 inverso e 1 peça nao é valido logo salta fora
        if (e.grelha[linha][c] == inverso) i = 1;
        if (e.grelha[linha][c] == e.peca) reg = 1;
        if (reg ==1 && i==1) return 1; // fucionará?
    }
    return 0;
}

int checkDiagDir(ESTADO e,int linha, int coluna){ // verifica se há uma jogada valida na Diagonal direita
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

int checkDiagEsq(ESTADO e,int linha, int coluna){ // verifica se há uma jogada valida na Diagonal direita
    int c = coluna;int l = linha; int reg = 0; int i = 0;
    VALOR inverso; // vamos crirar 1 variavel com o inverso da nossa peca de jogo de forma a confirmar que a jogada é valida
    if(e.peca == VALOR_X) inverso = VALOR_O;
    else inverso = VALOR_X;
    // Vamos procurar se a linha é valida apartir da posiçao dada, logo iremos correr a mesma 2 vezes
    while ((c < 7) || (l>0)){
        l--; c++;
        if (e.grelha[l][c] == VAZIA ) break; // se encontrar 1 local vazio antes de 1 inverso e 1 peça nao é valido logo salta fora
        if (e.grelha[l][c] == inverso) i = 1;
        if (e.grelha[l][c] == e.peca) reg = 1;
        if (reg ==1 && i==1) return 1; // fucionará?
    }
    c = coluna; l = linha;  reg = i = 0;
    while ((c > 0) || (l < 7)){
        l++; c--;
        if (e.grelha[l][c] == VAZIA ) break; // se encontrar 1 local vazio antes de 1 inverso e 1 peça nao é valido logo salta fora
        if (e.grelha[l][c] == inverso) i = 1;
        if (e.grelha[l][c] == e.peca) reg = 1;
        if (reg ==1 && i==1) return 1; // fucionará?
    }
    return 0;



//void virarPecas(ESTADO e,int linha,int coluna){}
