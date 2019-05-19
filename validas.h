//
// Created by pedro on 07/05/2019.
//

#ifndef LA_VALIDAS_H
#define LA_VALIDAS_H
ESTADO validasJogada(ESTADO e);
ESTADO retiraValida(ESTADO e);
ESTADO checkVal(ESTADO e,int linha,int coluna);

ESTADO checkVLinhadir(ESTADO e, int linha, int coluna);
ESTADO checkVLinhaesq(ESTADO e,int linha,int coluna);
ESTADO checkVColunabaixo(ESTADO e,int linha,int coluna);
ESTADO checkVColunacima(ESTADO e,int linha,int coluna);
ESTADO checkVDiagDirbaixo(ESTADO e,int linha,int coluna);
ESTADO checkVDiagDirCima(ESTADO e,int linha,int coluna);
ESTADO checkVDiagEsqbaixo(ESTADO e,int linha,int coluna);
ESTADO checkVDiagEsqcima(ESTADO e,int linha,int coluna);

ESTADO sugereJogada(ESTADO e);

#endif //LA_VALIDAS_H
