//
// Created by pedro on 02/05/2019.
//

#ifndef LA_JOGAR_H
#define LA_JOGAR_H

ESTADO jogar(ESTADO e,int l,int c);
//void virarPecas(ESTADO e,int linha,int coluna)
int jogadaValida (ESTADO, int, int);
ESTADO virapecas(ESTADO e,int linha , int coluna);
int isover(ESTADO e);
int isovervazias(ESTADO e);
int temvalidas(ESTADO e,VALOR p);
int isoversemjogadas(ESTADO e);
//VALOR oposta(VALOR v);

#endif //LA_JOGAR_H
