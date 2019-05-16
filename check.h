//
// Created by pedro on 15/05/2019.
//

#ifndef LA_CHECK_H
#define LA_CHECK_H
int check(ESTADO e,int linha,int coluna);
int checkLinhadir(ESTADO e,int linha,int coluna);
int checkLinhaesq(ESTADO e,int linha,int coluna);
int checkColunabaixo(ESTADO e,int linha, int coluna);
int checkColunacima(ESTADO e,int linha, int coluna);
int checkDiagDirCima(ESTADO e,int linha, int coluna);
int checkDiagDirbaixo(ESTADO e,int linha, int coluna);
int checkDiagEsqbaixo(ESTADO e,int linha, int coluna);
int checkDiagEsqcima(ESTADO e,int linha, int coluna);

#endif //LA_CHECK_H
