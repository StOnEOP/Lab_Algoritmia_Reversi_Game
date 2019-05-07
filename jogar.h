//
// Created by  Pedro Faria - A72640 02/05/2019.
//

#ifndef LA_JOGAR_H
#define LA_JOGAR_H

void jogar(ESTADO *e,int l,int c);
int jogadaValida(ESTADO e, int linha, int coluna);
//void virarPecas(ESTADO e,int linha,int coluna)
int checkHorizontal(ESTADO e,int linha,int coluna);
int validaVsup(ESTADO e,int l,int coluna);
int validaVinf(ESTADO e,int l,int coluna);
int checkColuna(ESTADO e,int linha, int coluna);
int checkDiagDir(ESTADO e,int linha, int coluna);
int checkDiagEsq(ESTADO e,int linha, int coluna);

#endif //LA_JOGAR_H
