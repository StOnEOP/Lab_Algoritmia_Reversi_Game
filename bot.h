//
// Created by pedro on 16/05/2019.
//

#ifndef LA_BOT_H
#define LA_BOT_H

ESTADO bot(ESTADO e, char peca);
ESTADO jogaBot (ESTADO e);
int selectJogada (ESTADO e, int* bLinha, int* bColuna);
int checkScore(ESTADO e,int l,int j);
#endif //LA_BOT_H
