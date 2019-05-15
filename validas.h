//
// Created by pedro on 07/05/2019.
//

#ifndef LA_VALIDAS_H
#define LA_VALIDAS_H
ESTADO validasJogada(ESTADO e);
ESTADO retiraValida(ESTADO e);
ESTADO checkVal(ESTADO e,int linha,int coluna);

void checkVLinhadir(ESTADO e,int linha,int coluna);
void checkVLinhaesq(ESTADO e,int linha,int coluna);
void checkVColunabaixo(ESTADO e,int linha,int coluna);
void checkVColunacima(ESTADO e,int linha,int coluna);
void checkVDiagDirbaixo(ESTADO e,int linha,int coluna);
void checkVDiagDirCima(ESTADO e,int linha,int coluna);
void checkVDiagEsqbaixo(ESTADO e,int linha,int coluna);
void checkVDiagEsqcima(ESTADO e,int linha,int coluna);

#endif //LA_VALIDAS_H
