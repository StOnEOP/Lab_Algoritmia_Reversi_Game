//
// Created by pedro on 02/05/2019.
//

#ifndef LA_JOGAR_H
#define LA_JOGAR_H

ESTADO jogar(ESTADO e,int l,int c);
//void virarPecas(ESTADO e,int linha,int coluna)
int checkLinhadir(ESTADO e,int linha,int coluna);
int checkLinhaesq(ESTADO e,int linha,int coluna);
int checkColunabaixo(ESTADO e,int linha, int coluna);
int checkColunacima(ESTADO e,int linha, int coluna);
int checkDiagDirCima(ESTADO e,int linha, int coluna);
int checkDiagDirbaixo(ESTADO e,int linha, int coluna);
int checkDiagEsqbaixo(ESTADO e,int linha, int coluna);
int checkDiagEsqcima(ESTADO e,int linha, int coluna);
int jogadaValida (ESTADO, int, int);
int check(ESTADO e,int linha,int coluna);
ESTADO virapecas(ESTADO e,int linha , int coluna);
VALOR inverte(VALOR);
//VALOR oposta(VALOR v);

#endif //LA_JOGAR_H
