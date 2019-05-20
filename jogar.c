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
    if (isover(e)==0){ // se jã nao houver jogadas possiveis
    /*else*/ if(jogadaValida(e,linha,coluna)) { // se a jogada for valida
            e.grelha[linha][coluna] = e.peca;   // poe a peça na coordenada selecionada
            e=virapecas(e,linha,coluna);        // vira as peças apartir da coordenada
            addHjogada(e.peca,linha,coluna);    // adiciona a jogada ao historico
            e.peca=inverte(e.peca);                  // inverte a peça para o proximo jogador
         } else printf("Jogada Invalida\n");

        return e;
    }


}

int jogadaValida(ESTADO e, int linha,int coluna){ //
    if(linha>=0 && linha <8 && coluna >=0 && coluna < 8 && e.grelha[linha][coluna]==VAZIA && check(e,linha,coluna) != 0){
        return 1;
    }else return 0;
}
int isover(ESTADO e){
    e=retiraValida(e);
    e=validasJogada(e);
   int r=isovervazias(e)+isoversemjogadas(e);
   e=retiraValida(e);
    return r;
}
int isovervazias(ESTADO e) {
    int cont=0;int r=0;
  for(int i=0;i<8;i++) {
      for (int j = 0; j < 8 && e.grelha[i][j] !=VAZIA && e.grelha[i][j] != VALIDA; j++){
          cont++;
      }

  }


  if(cont==64){
      r=1;
  }

    return r;

}

int isoversemjogadas(ESTADO e){

    if(temvalidas(e,e.peca)){
        return 0;


            }else return 1;

}

int temvalidas(ESTADO e,VALOR p) {
    int r = 0;int t=0;int tot=0;
    e=retiraValida(e);
    e=validasJogada(e);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (e.grelha[i][j] == VALIDA){
                r++;
            }
        }

    }

    p=inverte(p);
    e=retiraValida(e);

    e=validasJogada(e);
    for(int l=0;l<8;l++){
        for(int c=0;c<8;c++){
            if(e.grelha[l][c]==VALIDA){
               t++;
            }
        }
    }

    tot=r + t;

    return tot;

}

void vencedor(ESTADO e){
    if(isover(e)){
        int o=0,x=0;
        for(int i=0;i<8;i++) {   // muda linha
            for (int j = 0; j < 8; j++) { // muda coluna
                if (e.grelha[i][j] == VALOR_X) x++;
                if (e.grelha[i][j] == VALOR_O) o++;
            }
        }
        if(x>o){
            printf("\n****JOGO TERMINADO****\nO VENCEDOR E JOGADOR X !!!!!\n VENCEU COM X SCORE DE : %d \n",x);

        }else if(x<o){
            printf("\n****JOGO TERMINADO****\nO VENCEDOR E JOGADOR O !!!!!\n VENCEU COM O SCORE DE : %d \n",o);

        }else if(x==o){
            printf("\n****JOGO TERMINADO****\nO JOGO ACABOU EMPATADO!!!!!\n AMBOS TIVERAM UM SCORE DE : %d \n",x);

        }

    }
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
