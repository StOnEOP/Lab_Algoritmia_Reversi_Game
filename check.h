//
// Created by pedro on 15/05/2019.
//

#ifndef LA_CHECK_H
#define LA_CHECK_H
int check(ESTADO e,int linha,int coluna);
int checkLinhadir(ESTADO e,int linha,int coluna,VALOR p);
int checkLinhaesq(ESTADO e,int linha,int coluna,VALOR p);
int checkColunabaixo(ESTADO e,int linha, int coluna,VALOR p);
int checkColunacima(ESTADO e,int linha, int coluna,VALOR p);
int checkDiagDirCima(ESTADO e,int linha, int coluna,VALOR p);
int checkDiagDirbaixo(ESTADO e,int linha, int coluna,VALOR p);
int checkDiagEsqbaixo(ESTADO e,int linha, int coluna,VALOR p);
int checkDiagEsqcima(ESTADO e,int linha, int coluna,VALOR p);

#endif //LA_CHECK_H
