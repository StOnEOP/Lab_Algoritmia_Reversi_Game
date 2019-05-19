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
#include "bot.h"

ESTADO validasJogada(ESTADO e) { // recebe 1 estado e devolve um estado com jogadas validas
    // corre a funçao á procura de peças
    int i,j; VALOR inversa =inverte(e.peca);
    for (i = 0; i < 8; i++) {
        printf("Validas Linha %d\t",i);
        //printa(e);
        for (j = 0; j < 8; j++){
            printf("Validas Coluna %d\n",j);
            if(e.grelha[i][j]==inversa){ // procura peças inversa a nossa, ie locais onde sera possivel jogar
                printf("Validas precheckVal\n");
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
    e =checkVLinhadir(e, linha, coluna); e= checkVLinhaesq(e,linha,coluna);e = checkVColunabaixo(e, linha, coluna);
    e =checkVColunacima(e,linha, coluna);e= checkVDiagDirbaixo(e, linha, coluna);e= checkVDiagDirCima(e, linha,coluna);
    e =checkVDiagEsqbaixo(e,linha,coluna);printf("CHAMADA EM CHECKVAL pre VDIAGESQCIMA\n");e= checkVDiagEsqcima(e,linha,coluna);
    return e;
}

ESTADO checkVLinhaesq(ESTADO e,int linha,int coluna){ // verifica a linha á esquerda
    int c;
    if (e.grelha[linha][coluna+1] == VAZIA){ // como procura a esquerda, á direita tera de ter Vazia
        for(c=coluna-1;c>=0;c--){
            if (e.grelha[linha][c]==e.peca) {
                e.grelha[linha][coluna + 1] = VALIDA; //caso encontre torna a Vazia em Valida
                printf("V_LINHA_ESQ\n");
            }
        }
    }
    return e;
}

ESTADO checkVLinhadir(ESTADO e,int linha, int coluna){ // verifica a linha á direita
    int c;
    if (e.grelha[linha][coluna-1] == VAZIA){ // como procura a direita, á esquerda tera de ter Vazia
        for(c=coluna+1;c<8;c++){
            if (e.grelha[linha][c]==e.peca) {
                e.grelha[linha][coluna - 1] = VALIDA; //caso encontre torna a Vazia em Valida
                printf("V_LINHA_DIR\n");
            }
        }
    }
    return e;
}

ESTADO checkVColunabaixo(ESTADO e,int linha,int coluna){ // verifica a coluna para baixo e devolve a pontuaçao da jogada
    int l;
    if (e.grelha[linha-1][coluna] == VAZIA){ // como procura para baixo, a cima tera de ter Vazia
        for(l=linha+1;l<8;l++){
            if (e.grelha[l][coluna]==e.peca) {
                e.grelha[linha-1][coluna] = VALIDA; //caso encontre torna a Vazia em Valida
                printf("V_COL_Baixo\n");
            }
        }
    }
    return e;
}

ESTADO checkVColunacima(ESTADO e,int linha,int coluna){ // verifica a coluna para cima e devolve a pontuaçao da jogada
    int l;
    if (e.grelha[linha+1][coluna] == VAZIA){    // como procura para cima, a baixo tera de ter Vazia
        for(l=linha-1;l>=0;l--){            // procura apartir da peça
            if (e.grelha[l][coluna]==e.peca) {
                e.grelha[linha+1][coluna] = VALIDA; //caso encontre torna a Vazia em Valida
                printf("V_COL_CIMA\n");
            }
        }
    }
    return e;
}

ESTADO checkVDiagDirbaixo(ESTADO e,int linha, int coluna) {
    int l,c;
    if (e.grelha[linha - 1][coluna -1] == VAZIA) {
        for(l=linha+1, c=coluna+1;l<8 && c<8;l++, c++) {
                if (e.grelha[l][c] == e.peca) {
                    e.grelha[linha - 1][coluna - 1] = VALIDA;
                    printf("V_Ddir_baixo\n");
                }
            }
    }
    return e;
}

ESTADO checkVDiagDirCima(ESTADO e,int linha, int coluna) {
    int l,c;
    if (e.grelha[linha +1][coluna -1] == VAZIA) {
        for(l=linha-1, c=coluna+1;l>=0 && c<8;l--, c++) { //2
                if (e.grelha[l][c] == e.peca) {
                    e.grelha[linha + 1][coluna - 1] = VALIDA;
                    printf("V_Ddir_Cima\n");
                }
            }
    }
    return e;
}

ESTADO checkVDiagEsqbaixo(ESTADO e,int linha, int coluna) {
    int l,c;
    if (e.grelha[linha - 1][coluna + 1] == VAZIA) {
        for(l=linha+1, c=coluna-1;l < 8 && c>=0;l++, c--) { //2
                if (e.grelha[l][c] == e.peca) {
                    e.grelha[linha - 1][coluna + 1] = VALIDA;
                    printf("V_Desq_Baixo\n");
                }
            }
    }
    return e;
}

ESTADO checkVDiagEsqcima(ESTADO e,int linha, int coluna) {
    int l,c;
    if (e.grelha[linha + 1][coluna + 1] == VAZIA) {
        for(l=linha-1,c=coluna-1 ;l>=0 && c>=0;l--, c--){//2
                if (e.grelha[l][c] == e.peca) {
                    e.grelha[linha + 1][coluna + 1] = VALIDA;
                    printf("V_Desq_cima\n");
                }
            }
    }
    return e;
}

int sugereJogada(ESTADO e){    // como a sugestao imprime dentro da funçao, nao precisa de retornar nada, logo retorna 0 se completada com sucesso e 1 caso contrario
    validasJogada(e);int exit=1;           // poe VALOR VALIDA em todas as jogadas validas
    int linha=-1;int coluna=-1;             // valores para testar se ja foram usados
    int tmp,r=0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (e.grelha[i][j] == VALIDA){  //se a posiçao for 1 jogada valida
                e.grelha[i][j] = VAZIA;     //limpa a VALIDA, para o checkScore funcionar
                tmp = checkScore(e,i,j);    //poe o valor de checkscore em tmp
                if (tmp > r){               //se o valor da posiçao atual for maior que o da posiçao guardada
                    r = tmp;                // guarda esse valor em temp
                    if (linha >=0) e.grelha[linha][coluna] = VAZIA;    //caso ja tenha guardado uma posiçao anterior limpa a ultima posiçao usada
                    e.grelha[i][j]= SUGESTAO;           //poe VALOR SUGESTAO na nova posiçao
                    linha = i;coluna = j;               //guarda o valor da posiçao r
                }
            }
        }

    }
    if (e.grelha[linha][coluna] = SUGESTAO) {   // se houver 1 sugestao
        printa(e);                              // imprime o tabuleiro com a sugestao
        e.grelha[linha][coluna] = VAZIA;        // limpa a sugestao do tabuleiro
        exit =0;
    }
    return exit;
}