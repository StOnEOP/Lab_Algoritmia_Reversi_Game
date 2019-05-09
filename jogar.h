//
// Created by pedro on 02/05/2019.
//

#ifndef LA_JOGAR_H
#define LA_JOGAR_H

void jogar(ESTADO *e,int l,int c);
void jogadaValida(ESTADO *e,int linha,int coluna);
//void virarPecas(ESTADO e,int linha,int coluna)
int checkLinha(ESTADO *e,int linha,int coluna);
int checkColuna(ESTADO *e,int linha, int coluna);
int checkDiagDir(ESTADO *e,int linha, int coluna);
int checkDiagEsq(ESTADO *e,int linha, int coluna);
void limpavalidas(ESTADO *e);
void check(ESTADO *e,int linha,int coluna);
void pontos(ESTADO e);
//VALOR oposta(VALOR v);

#endif //LA_JOGAR_H
