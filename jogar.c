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
#include "validas.h"




ESTADO jogar(ESTADO e,int linha,int coluna) {
    //if (isover) printf("Jogo Terminado\n"); // se jã nao houver jogadas possiveis
    //*else*/ if(jogadaValida(e,linha,coluna)) { // se a jogada for valida
            e.grelha[linha][coluna] = e.peca;   // poe a peça na coordenada selecionada
            e=virapecas(e,linha,coluna);        // vira as peças apartir da coordenada
            addHjogada(e.peca,linha,coluna);    // adiciona a jogada ao historico
            e.peca=inverte(e.peca);                  // inverte a peça para o proximo jogador
         //} else printf("Jogada Invalida\n");

        return e;


}

int jogadaValida(ESTADO e, int linha,int coluna){ //
    if(linha>=0 && linha <8 && coluna >=0 && coluna < 8 && e.grelha[linha][coluna]==VAZIA && check(e,linha,coluna) != 0){
        return 1;
    }else return 0;
}
int isover(ESTADO e){
    retiraValida(e);
    validasJogada(e);
   if(isoversemjogadas(e)||isovervazias(e)){
       return 1;
   }else return 0;
}
int isovervazias(ESTADO e) {
    int r=1;
  for(int i=0;i<8;i++) {
      for (int j = 0; j < 8; j++) {
          if (e.grelha[i][j] == VAZIA) {
              r = 0;
              break;
          }
      }
  }
    return r;
}

int isoversemjogadas(ESTADO e){
    int r=1;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(temvalidas(e)){
                r=0;
                break;

            }



        }

    }
    return r;
}
int temvalidas(ESTADO e) {
    int r = 0;
    retiraValida(e);
    validasJogada(e);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (e.grelha[i][j] == VALIDA) {
                r++;
            }
        }

    }
    return r;
}

/*
 * TODO:
 *  O tabuleiro está completamente preenchido nas suas 64 posições. Ganha quem tiver mais
peças no tabuleiro
 Nenhum jogador tem uma jogada válida disponível. Ganho o jogador com mais peças no
tabuleiro
 Só há peças no tabuleiro de um jogador. Consequentemente o oponente não tem jogadas
válidas. O jogador também não pode cercar peças do oponente! Logo o jogo termina e ganha
este jogador (caso especial da situação anterior).
 */
